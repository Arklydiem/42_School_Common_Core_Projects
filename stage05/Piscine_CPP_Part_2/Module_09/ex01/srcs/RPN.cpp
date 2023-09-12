/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:09:28 by argomez           #+#    #+#             */
/*   Updated: 2023/04/12 13:46:53 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	isOperator(char c){
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return (true);
	return (false);
}

void	RPN::run(int argc, char* argv[]){
	if (argc != 2 || argv[1][0] == '\0')
		throw RPN::RPNErrorException();
	std::stack<int>	intStack;
	std::string toOperate = argv[1];
	for (size_t i = 0; toOperate[i]; i++){
		// Check if the string is correctly configured
		if (i % 2 == 1 && toOperate[i] != ' ')
			throw RPN::RPNErrorException();
		else if (i % 2 == 0 && (!isdigit(toOperate[i]) && !isOperator(toOperate[i])))
			throw RPN::RPNErrorException();
		if (i % 2 == 1 && toOperate[i] == ' ')
			continue;
		if (isdigit(toOperate[i]))
		{
			intStack.push(toOperate[i] - 48);
			continue;
		}
		if (intStack.size() < 2)
			throw RPN::RPNErrorException();
		int	y = intStack.top();
		intStack.pop();
		int	x = intStack.top();
		switch (toOperate[i])
		{
			case '*':
				intStack.top() = x * y;
				break;
			case '/':
				if (y == 0)
					throw RPN::RPNErrorException();
				intStack.top() = x / y;
				break;
			case '+':
				intStack.top() = x + y;
				break;
			case '-':
				intStack.top() = x - y;
				break;
		}
	}
	if (intStack.size() > 1)
		throw RPN::RPNErrorException();
	std::cout << "Result : " << intStack.top() << std::endl;
}

const char* RPN::RPNErrorException::what() const throw(){
	return ("\e[38;5;196mError\e[0m");
}