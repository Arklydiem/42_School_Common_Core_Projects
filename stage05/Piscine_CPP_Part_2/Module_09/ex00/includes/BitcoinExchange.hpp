/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:53:18 by argomez           #+#    #+#             */
/*   Updated: 2023/04/14 17:56:54 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BITCOINEXCHANGE_HPP
# define	BITCOINEXCHANGE_HPP

# include	<exception>
# include	<iostream>
# include	<fstream>
# include	<map>
# include	<cstdlib>
# include	<cstring>
# include	<ctime>

class BitcoinExchange
{
	private:
		BitcoinExchange();	
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);	
		~BitcoinExchange();
		
	protected:

	public:
		class ArgumentsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class OpenFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class DateFormatException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class BigNumberException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NegativeNumberException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class DataBaseFormatException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class DataBaseDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class DataBaseEmptyException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InputEmptyFormatException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InputFormatException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class OutOfDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		static void	run(int argc, char* argv[]);
};


#endif