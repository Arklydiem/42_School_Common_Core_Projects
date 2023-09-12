/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:17:02 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 14:29:29 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

static	int			_robotomyCount = 0;

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "<isNdef>", 72, 45){
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45){
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj){
	*this = obj;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj){
	if (this != &obj)
		this->AForm::operator=(obj);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	return ;
}

void	RobotomyRequestForm::execute(const Bureaucrat &obj) const{
	if (this->getSignatureState() == false)
		throw StatuSignatureExeception();
	if (this->getGradeToExecute() < obj.getGrade())
		throw GradeTooLowExeception();
	std::cout << "*-.Drill noises.-*" << std::endl;
	if (_robotomyCount++ % 2 == 1){
		std::cout << "Robotomized on " << this->getTarget() << " failed." << std::endl;
		return ;
	}
	std::cout << this->getTarget() << " has been Robotomized." << std::endl;
}
