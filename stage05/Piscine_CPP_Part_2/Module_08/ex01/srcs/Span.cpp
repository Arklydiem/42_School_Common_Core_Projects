/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:34:10 by argomez           #+#    #+#             */
/*   Updated: 2023/04/07 10:34:47 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(/* args */) : _maxNumbers(0){
	return ;
}

Span::Span(unsigned int N) : _maxNumbers(N){
	return ;
}

Span::Span(const Span& obj){
	*this = obj;
}

Span& Span::operator=(const Span& obj){
	if (this == &obj)
		return (*this);
	if (_intVector.size() > 0)
		_intVector.resize(0);
	_intVector.resize(obj._maxNumbers);
	_intVector.insert(_intVector.begin(), obj._intVector.begin(), obj._intVector.end());
	_maxNumbers = obj._maxNumbers;
	return (*this);
}

Span::~Span(){
	return ;
}

void	Span::addNumber(int	number){
	unsigned int size = _intVector.size();
	if (_maxNumbers <= size)
		throw NotEnoughSpaceInSpanException();
	_intVector.push_back(number);
}

void	Span::addNumbers(const std::vector<int>::iterator& start, const std::vector<int>::iterator& end){
	unsigned int addBase = 0;
	for (std::vector<int>::iterator i = start; i != end; i++)
		addBase++;
	unsigned int baseSize = _intVector.size();
	if (baseSize + addBase <= _maxNumbers)
		_intVector.insert(_intVector.end(), start, end);
	else
		throw NotEnoughSpaceInSpanException();
}

unsigned int	Span::shortestSpan(void) const{
	long long span = 4294967295;
	long long tmp;
	if (_intVector.size() < 2)
		throw NotEnoughNumbersInSpanException();
	for (size_t i = 0; i < _intVector.size(); i++)
	{
		for (size_t j = i + 1; j < _intVector.size(); j++)
		{
			tmp = (long)_intVector[i] - (long)_intVector[j];
			if (tmp < 0)
				tmp *= -1;
			if (tmp < span)
				span = tmp;
		}
	}
	return (span);
}

unsigned int	Span::longestSpan(void) const{

	int	max = *std::max_element(_intVector.begin(), _intVector.end());
	int	min = *std::min_element(_intVector.begin(), _intVector.end());
	return max - min;
}

void			Span::displaySpan(void) const{
	for (size_t i = 0; i < _intVector.size(); i++)
		std::cout << _intVector[i] << std::endl;
}

const char*		Span::NotEnoughSpaceInSpanException::what() const throw(){
	return ("Not Enough Space In The Span To Add More Number");
}

const char*		Span::NotEnoughNumbersInSpanException::what() const throw(){
	return ("Not Enough Numbers In The Span To Find A Shortest or Longest Span");
}