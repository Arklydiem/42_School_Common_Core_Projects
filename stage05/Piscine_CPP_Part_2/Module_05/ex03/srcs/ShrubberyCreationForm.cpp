/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:17:51 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 15:11:52 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "<isNdef>", 145, 137){
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137){
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj){
	*this = obj;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj){
	if (this != &obj){
		this->AForm::operator=(obj);
	}
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &obj)	const{
	if (this->getSignatureState() == false)
		throw StatuSignatureExeception();
	if (this->getGradeToExecute() < obj.getGrade())
		throw GradeTooLowExeception();
	std::ofstream out;
	out.open ((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out);
	if (!out){
	    std::cout << "Impossible to open : " << this->getTarget() << "_shrubbery" << std::endl;
	    return ;
	}
	for (size_t i = 0; i < 2; i++)
	{
		out << "                       ___\n"
			<< "                _,-'\"\"   \"\"\"\"`--.\n"
			<< "             ,-'          __,,-- \n"
			<< "           ,'    __,--\"\"\"\"dF      )\n"
			<< "          /   .-\"Hb_,--\"\"dF      /\n"
			<< "        ,'       _Hb ___dF\"-._,-'\n"
			<< "      ,'      _,-\"\"\"\"   \"\"--..__\n"
			<< "     (     ,-'                  `.\n"
			<< "      `._,'     _   _             ;\n"
			<< "       ,'     ,' `-'Hb-.___..._,-'\n"
			<< "       \\    ,'\"Hb.-'HH`-.dHF\"\n"
			<< "        `--'   \"Hb  HH  dF\"\n"
			<< "                \"Hb HH dF\n"
			<< "                 \"HbHHdF\n"
			<< "                  |HHHF\n"
			<< "                  |HHH|\n"
			<< "                  |HHH|\n"
			<< "                  |HHH|"
			<< "                  |HHH|\n"
			<< "                  dHHHb\n"
			<< "                .dFd|bHb.               o\n"
			<< "      o       .dHFdH|HbTHb.          o /\n"
			<< "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n"
			<< "##########################################\n"
			<< std::endl << std::endl;
	}
	out.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	return ;
}
