/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:53 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 14:11:22 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), 
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0) {
	++_nbAccounts;
	this->_totalAmount += this->_amount;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
			<< ";created" << std::endl;
	return ;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
			<< ";closed" << std::endl;
	return ;
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

Account::Account( void ) {
	return ;
}

void	Account::_displayTimestamp( void ) {
	std::time_t curr_time = std::time(0);
	std::tm* 	now = std::localtime(&curr_time);

	std::cout << '[' << (now->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (now->tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) <<  now->tm_mday;
	std::cout << '_';
	std::cout << std::setfill('0') << std::setw(2) <<  now->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) <<  now->tm_min;
	std::cout << std::setfill('0') << std::setw(2) <<  now->tm_sec;
	std::cout << "] ";
	// std::cout << "[19920104_091532] ";
}

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << getTotalAmount() << ';';
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	std::cout << "deposit:" << deposit << ';';
	this->_amount += deposit;
	_totalAmount += deposit;
	++_totalNbDeposits;
	std::cout << "amount:" << this->_amount << ';';
	++this->_nbDeposits;
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	this->_amount -= withdrawal;
	if (checkAmount()) {
		_totalAmount += withdrawal;
		++_totalNbWithdrawals;
		std::cout << "withdrawal:" << withdrawal << ';';
		std::cout << "amount:" << this->_amount << ';';
		++this->_nbWithdrawals;
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	} else {
		this->_amount += withdrawal;
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const {
	return (this->_amount >= 0);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}
