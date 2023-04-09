/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:17:13 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/04 09:17:13 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <cstdint>

class Serializer {

private:
	Serializer( void );
	Serializer( const Serializer &other );
	~Serializer( void );
	Serializer &operator=( const Serializer &other );

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

#endif
