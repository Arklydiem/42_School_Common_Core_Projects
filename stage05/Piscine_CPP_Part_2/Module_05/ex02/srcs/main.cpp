/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:32:29 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 13:44:18 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"
#include	"ShrubberyCreationForm.hpp"
#include	"RobotomyRequestForm.hpp"
#include	"PresidentialPardonForm.hpp"

int main(void)
{
	{
		std::cout << "\e[38;5;42m\t=============== PresidentialPardonForm TESTS =============== \e[0m" << std::endl;
		try
		{
			PresidentialPardonForm Form("Target");
			PresidentialPardonForm Form2("Target2");
			Bureaucrat TestB("Test", 5);
			TestB.signForm(Form);
			TestB.executeForm(Form);
			std::cout << Form2 << std::endl;
			Form2 = Form;
			std::cout << Form2 << std::endl;
		}
		catch (std::exception const&e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm Form("Target");
			Bureaucrat TestB("Test", 25);
			TestB.signForm(Form);
			TestB.executeForm(Form);
		}
		catch (std::exception const&e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm Form("Target");
			Bureaucrat TestB("Test", 26);
			TestB.signForm(Form);
			TestB.executeForm(Form);
		}
		catch (std::exception const&e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\e[38;5;42m\t=============== ShrubberyCreationForm TESTS =============== \e[0m" << std::endl;
		try
		{
			ShrubberyCreationForm Form("Target");
			Bureaucrat TestB("Test", 137);
			TestB.signForm(Form);
			TestB.executeForm(Form);
		}
		catch (std::exception const&e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm Form("Target");
			Bureaucrat TestB("Test", 145);
			TestB.signForm(Form);
			TestB.executeForm(Form);
		}
		catch (std::exception const&e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm Form("Target");
			Bureaucrat TestB("Test", 146);
			TestB.signForm(Form);
			TestB.executeForm(Form);
		}
		catch (std::exception const&e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\e[38;5;42m\t=============== RobotomyRequestForm TESTS =============== \e[0m" << std::endl;

		try
		{
			RobotomyRequestForm Form("Target");
			Bureaucrat TestB("Test", 45);
			TestB.signForm(Form);
			TestB.executeForm(Form);
		}
		catch (std::exception const&e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm Form("Target");
			Bureaucrat TestB("Test", 71);
			TestB.signForm(Form);
			TestB.executeForm(Form);
		}
		catch (std::exception const&e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm Form("Target");
			Bureaucrat TestB("Test", 73);
			TestB.signForm(Form);
			TestB.executeForm(Form);
		}
		catch (std::exception const&e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
