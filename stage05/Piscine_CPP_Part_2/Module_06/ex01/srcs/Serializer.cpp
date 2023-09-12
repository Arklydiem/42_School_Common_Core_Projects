/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:32:44 by argomez           #+#    #+#             */
/*   Updated: 2023/03/29 11:37:15 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr){
	return (reinterpret_cast <uintptr_t> (ptr));
}

Data*		Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast <Data*> (raw));
}