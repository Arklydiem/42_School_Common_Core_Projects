/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:25:52 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 15:15:30 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static const std::string availableForm[3] = {"PresidentialPardonForm",
											"RobotomyRequestForm",
											"ShrubberyCreationForm"};

Intern::Intern(){
	return ;
}

Intern::Intern(const Intern& obj){
	*this = obj;
	return ;
}

Intern&	Intern::operator=(const Intern& obj){
	(void)obj;
	return (*this);
}

Intern::~Intern(){
	return ;
}

AForm*	Intern::makeForm(std::string name, std::string target) const{
	int	i;
	for (i = 0;i < 3; i++)
	{
		if (availableForm[i] == name)
			break;
	}
	AForm	*form;
	switch (i)
	{
		case 0:
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates PresidentialPardonForm." <<std::endl;
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates RobotomyRequestForm." <<std::endl;
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates ShrubberyCreationForm." <<std::endl;
			break;
		default:
			form = NULL;
			std::cout << "Wrong Form Type" <<std::endl;
			break;
	}
	return form;
}
