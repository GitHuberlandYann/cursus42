/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:53 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 12:06:54 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit) {
	return ;
}

Account::~Account(void) {
	return ;
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

Account::Account(void) {
	return ;
}

static void	_displayTimestamp( void ) {
	
}

// ************************************************************************** //
//                                    Main                                    //
// ************************************************************************** //

static int	getNbAccounts( void );
static int	getTotalAmount( void );
static int	getNbDeposits( void );
static int	getNbWithdrawals( void );
static void	displayAccountsInfos( void );

void	makeDeposit( int deposit );
bool	makeWithdrawal( int withdrawal );
int		checkAmount( void ) const;
void	displayStatus( void ) const;
