/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:28:04 by argomez           #+#    #+#             */
/*   Updated: 2023/03/30 14:29:16 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename Array>
void	display(const Array& obj){
	std::cout << obj;
}

int main( void ) {
	char		arr1[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	int 		arr2[4] = {1, 2, 3, 4};
	std::string	arr3[5] = {"Je", " suis ", "le ", "plus", " bÔ"};

	::iter(arr1, 8, &display);
	std::cout << std::endl;
	::iter(arr1, 10, &display);
	std::cout << std::endl;
	::iter(arr2, 4, &display);
	std::cout << std::endl;
	::iter(arr3, 5, &display);
	std::cout << std::endl;

return 0;
}
