/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:02:29 by argomez           #+#    #+#             */
/*   Updated: 2023/04/12 13:57:33 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RPN_HPP
# define	RPN_HPP

# include	<iostream>
# include	<stack>
# include	<exception>

class RPN
{
	private:
		RPN(/* Args */);
		RPN(const RPN& obj);
		RPN& operator=(const RPN& obj);
		~RPN(/* Args */);
	protected:

	public:
		class RPNErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		static void	run(int argc, char* argv[]);
};


#endif