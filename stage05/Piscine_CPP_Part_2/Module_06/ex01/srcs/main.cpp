/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:32:29 by argomez           #+#    #+#             */
/*   Updated: 2023/03/29 12:17:17 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Serializer.hpp"

int main(void)
{
	Data		test;
	Data		*tmp;
	uintptr_t	serialized = 0;

	test.index = 150;

	std::cout << "test Adress :" << &test << std::endl;
	std::cout << "test index value :" << test.index << std::endl;

	serialized = Serializer::serialize(&test);

	tmp = Serializer::deserialize(serialized);
	std::cout << "tmp Adress :" << &test << std::endl;
	std::cout << "tmp index value :" << tmp->index << std::endl;
	return 0;
}
