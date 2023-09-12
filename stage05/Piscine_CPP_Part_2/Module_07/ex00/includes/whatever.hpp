/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:53:18 by argomez           #+#    #+#             */
/*   Updated: 2023/03/30 13:42:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WHATEVER_HPP
# define	WHATEVER_HPP

# include	<iostream>

template <typename Type>
void swap(Type& x, Type& y){
	Type tmp = x;
	x = y;
	y = tmp;
}

template <typename Type>
const Type& max(const Type& x, const Type& y){
	return (x > y ? x : y);
}

template <typename Type>
const Type& min(const Type& x, const Type& y){
	return (x < y ? x : y);
}

#endif
