/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:37:21 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 13:26:09 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("<isNdef>"), _grade(150){
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade < 1)
		throw GradeTooHighExeception();
	else if (grade > 150)
		throw GradeTooLowExeception();
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj.getName()){
	*this = obj;
	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj){
	if (this != &obj){
		this->_grade = obj.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){
	return ;
}

const	std::string	Bureaucrat::getName()						const{
	return (this->_name);
}

		int			Bureaucrat::getGrade()						const{
	return (this->_grade);
}

void	Bureaucrat::promote(){
	if (this->_grade - 1 < 1)
		throw GradeTooHighExeception();
	else
		this->_grade--;
}

void	Bureaucrat::demote(){
	if (this->_grade + 1 > 150)
		throw GradeTooLowExeception();
	else
		this->_grade++;
}

		void		Bureaucrat::signForm(Form &obj)				const{
	try
	{
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn’t sign " << obj.getName() << " because " << e.what() << std::endl;
	}
	
}

const	char*		Bureaucrat::GradeTooHighExeception::what()	const	throw(){
	return ("GradeTooHigh");
}

const	char*		Bureaucrat::GradeTooLowExeception::what()	const	throw(){
	return ("GradeTooLow");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj){
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." ;
    return out;
}
