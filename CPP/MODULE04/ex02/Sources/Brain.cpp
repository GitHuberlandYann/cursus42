/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:42:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain( void ) {
	std::cout << "Default constructor of Brain called" << std::endl;
	return ;
}


Brain::Brain( const Brain &other ) {
	std::cout << "Copy constructor of Brain called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	return ;
}

Brain::~Brain( void ) {
	std::cout << "Destructor of Brain called" << std::endl;
	return ;
}

Brain &Brain::operator=( const Brain &other ) {
	std::cout << "Copy assignment operator of Brain called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void		Brain::setIdea( int index, const std::string idea ) {
	if (index < 0 || index > 99) {
		return ;
	}
	this->_ideas[index] = idea;
}

void		Brain::addIdea( const std::string idea ) {
	this->_ideas[this->_curr_idea] = idea;
	++this->_curr_idea;
	if (this->_curr_idea == 100) {
		this->_curr_idea = 0;
	}
}

std::string	Brain::getIdea( int index ) {
	if (index < 0 || index > 99) {
		std::string	res;
		return (res);
	}
	return (this->_ideas[index]);
}
