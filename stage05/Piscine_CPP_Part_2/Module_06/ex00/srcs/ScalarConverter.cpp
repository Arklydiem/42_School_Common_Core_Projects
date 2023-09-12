/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:46:19 by argomez           #+#    #+#             */
/*   Updated: 2023/03/29 15:22:57 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ScalarConverter.hpp"

	static char			cResult;
	static int			iResult;
	static float		fResult;
	static double		dResult;
	static int			precision = 1;
	static std::string	tmp;
	static bool			isNAN = false;
	static bool			isNeg = false;

int		defineType(std::string toConvert){
	int	length = toConvert.length();
	if (length == 0 || (length == 1 && !std::isdigit(toConvert[0])))
		return (CHAR);

	int	count = 0;
	if (toConvert.c_str()[0] == '-')
	{
		isNeg = true;
		count++;
	}
	while (toConvert.c_str()[count] && isdigit(toConvert.c_str()[count]))
		count++;
	if (count == length && (strtol(toConvert.c_str(), NULL, 10) >= -2147483648) && strtol(toConvert.c_str(), NULL, 10) <= 2147483647)
		return (INT);
	
	char	*secondPart;
	std::strtod(toConvert.c_str(), &secondPart);

	if (toConvert == "nan" || toConvert == "nanf")
		isNAN = true;
	
	char*	pEnd;
	std::strtol(toConvert.c_str(), &pEnd, 10);
	tmp = pEnd;

	if ((length >= 3 && secondPart[0] == 'f' && secondPart[1] == '\0' && (int)(toConvert.find(".")) != -1) || toConvert == "+inff" || toConvert == "-inff" || isNAN)
		return(FLOAT);
	
	if (((length >= 2 && secondPart[0] == '\0') && (int)(toConvert.find(".")) != -1) || toConvert == "+inf" || toConvert == "-inf" || isNAN)
		return(DOUBLE);
	return (0);
}

void	charDisplay(){
	if (dResult < 0 || dResult > 127 || std::isnan(dResult))
		std::cout << "char   : " << "impossible" << std::endl;
	else if (std::isprint(cResult) != false)
		std::cout << "char   : '" << cResult << "'" << std::endl;
	else
		std::cout << "char   : " << "Non displayable" << std::endl;
}

void	intDisplay(){
	if (dResult < -2147483648 || dResult > 2147483647 || std::isnan(dResult))
		std::cout << "int    : " << "impossible" << std::endl;
	else
		std::cout << "int    : " << iResult << std::endl;
}

void	manageResults(){
	charDisplay();
	intDisplay();
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float  : " << fResult << "f" << std::endl;
	std::cout << "double : " << dResult << std::endl;
}

void	ScalarConverter::convert(std::string toConvert){
	int	type = defineType(toConvert);

	switch (type)
	{
		case CHAR:
		{
			cResult = toConvert.c_str()[0];
			iResult = static_cast<int>(cResult);
			fResult = static_cast<float>(cResult);
			dResult = static_cast<double>(cResult);
			break;
		}
		case INT:
		{
			iResult = strtol(toConvert.c_str(), NULL, 10);
			cResult = static_cast<char>(iResult);
			fResult = static_cast<float>(strtol(toConvert.c_str(), NULL, 10));
			dResult = static_cast<double>(strtol(toConvert.c_str(), NULL, 10));
			break;
		}
		case FLOAT:
		{
			fResult = strtof(toConvert.c_str(), NULL);
			cResult = static_cast<char>(fResult);
			iResult = static_cast<int>(fResult);
			dResult = static_cast<double>(fResult);
			if (tmp.length() > 1)
				precision = tmp.length() - 2 - isNeg;
			if (precision == 0)
				precision++;
			break;
		}
		case DOUBLE:
		{
			dResult = strtod(toConvert.c_str(), NULL);
			cResult = static_cast<char>(dResult);
			iResult = static_cast<int>(dResult);
			fResult = static_cast<float>(dResult);
			if (tmp.length() > 1)
				precision = tmp.length() - 1 - isNeg;
			if (precision == 0)
				precision++;
			break;
		}
		default:
		{
			std::cout << "Error : Impossible to Scalar a String." <<std::endl;
			return;
		}
	}
	manageResults();
}
