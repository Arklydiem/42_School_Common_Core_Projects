/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:18:17 by vnadal            #+#    #+#             */
/*   Updated: 2023/04/29 16:17:32 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_irc.h"

class Error
{
	public:

		/* ************************************************************************** */
		/*                                  METHODS                                   */
		/* ************************************************************************** */
		
		static void printError(std::string msg)
		{
			std::cerr << msg << std::endl;
		}
		
	private:

		/* ************************************************************************** */
		/*                                CONSTRUCTOR                                 */
		/* ************************************************************************** */
		
		Error();
		Error(const Error& copy);
		
		/* ************************************************************************** */
		/*                                DESTRUCTOR                                  */
		/* ************************************************************************** */
		
		~Error();

		/* ************************************************************************** */
		/*                                 OPERATOR                                   */
		/* ************************************************************************** */
		
		Error& operator=(const Error& copy);
};
