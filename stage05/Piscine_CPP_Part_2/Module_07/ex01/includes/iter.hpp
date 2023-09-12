/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:53:18 by argomez           #+#    #+#             */
/*   Updated: 2023/03/30 14:25:24 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ITER_HPP
# define	ITER_HPP

# include	<iostream>

template <typename Array>
void iter(Array* address, size_t size, void (*func)(const Array&)){
	for (size_t i = 0; i < size; i++)
	{
		func(address[i]);
	}
}


#endif
