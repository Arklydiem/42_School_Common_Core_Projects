/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:22:06 by argomez           #+#    #+#             */
/*   Updated: 2023/03/29 12:10:36 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SERIALIZER_HPP
# define	SERIALIZER_HPP

#include	<stdint.h>

struct Data
{
	int	index;
};

class Serializer
{
	private:
		Serializer(/* args */);
		Serializer(const Serializer& obj);
		Serializer* operator=(const Serializer& obj);
		~Serializer();
	
	protected:
	
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif