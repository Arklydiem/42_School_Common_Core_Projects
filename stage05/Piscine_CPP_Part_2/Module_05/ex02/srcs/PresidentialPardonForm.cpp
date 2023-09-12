/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:25:12 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 14:29:16 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "<isNdef>", 25, 5){
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5){
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj){
	*this = obj;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj){
	if (this != &obj)
		this->AForm::operator=(obj);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	return ;
}

void	PresidentialPardonForm::execute(const Bureaucrat &obj) const{
	if (this->getSignatureState() == false)
		throw StatuSignatureExeception();
	if (this->getGradeToExecute() < obj.getGrade())
		throw GradeTooLowExeception();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}