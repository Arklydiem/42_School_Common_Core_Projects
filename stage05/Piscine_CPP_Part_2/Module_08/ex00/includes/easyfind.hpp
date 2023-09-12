/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:53:18 by argomez           #+#    #+#             */
/*   Updated: 2023/04/07 10:01:48 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		EASYFIND_HPP
# define	EASYFIND_HPP

#include	<algorithm>
#include	<iostream>

template <class T>
void easyfind(T& intContainer, int toFind){
	if (std::find(intContainer.begin(), intContainer.end(), toFind) == intContainer.end())
		std::cout << "Element not Found" << std::endl;
	else	
		std::cout << "Element Found" << std::endl;
}

#endif
	