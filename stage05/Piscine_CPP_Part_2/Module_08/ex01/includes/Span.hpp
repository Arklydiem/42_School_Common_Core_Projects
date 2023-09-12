/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:53:18 by argomez           #+#    #+#             */
/*   Updated: 2023/04/07 10:25:26 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SPAN_HPP
# define	SPAN_HPP

# include	<cstdlib>
# include	<exception>
# include	<vector>
# include	<iostream>
# include	<algorithm>


class Span
{
	private:
		unsigned int		_maxNumbers;
		class NotEnoughSpaceInSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotEnoughNumbersInSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
	public:
		Span(/* args */);
		Span(unsigned int N);
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span();

		void			addNumber(int toAdd);
		void			addNumbers(const std::vector<int>::iterator& start, const std::vector<int>::iterator& end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		void			displaySpan() const;
		
		std::vector<int>	_intVector;
};

#endif
	