/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:32:29 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 13:56:21 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"
#include	"ShrubberyCreationForm.hpp"
#include	"RobotomyRequestForm.hpp"
#include	"PresidentialPardonForm.hpp"
#include	"Intern.hpp"

int main(void)
{
	{
		std::cout << "\e[38;5;42m\t=============== Intern TESTS =============== \e[0m" << std::endl;

		std::cout << "Creation of one intern :" << std::endl;
		Intern	one;
		std::cout << std::endl;

		std::cout << "Creation of one intern by copy:" << std::endl;
		Intern	two(one);
		std::cout << std::endl;

		std::cout << "Assignation of an intern to an other :" << std::endl;
		one = two;
		std::cout << std::endl;
	}
	{
		std::cout << "\e[38;5;42m\t=============== makeForm TESTS =============== \e[0m" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("blap", "Bender");
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		rrf = someRandomIntern.makeForm("blep", "Bender");
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		rrf = someRandomIntern.makeForm("blip", "Bender");
		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		delete rrf;
	}
	
}
