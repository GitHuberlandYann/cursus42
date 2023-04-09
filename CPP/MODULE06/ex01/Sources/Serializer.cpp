/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:25:33 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/04 09:25:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer( void ) {
	std::cout << "Default constructor of Serializer called" << std::endl;
	return ;
}

Serializer::Serializer( const Serializer &other ) {
	std::cout << "Copy constructor of Serializer called" << std::endl;
	*this = other;
	return ;
}

Serializer::~Serializer( void ) {
	std::cout << "Destructor of Serializer called" << std::endl;
	return ;
}

Serializer &Serializer::operator=( const Serializer &other ) {
	std::cout << "Copy assignment operator of Serializer called" << std::endl;
	(void)other;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
