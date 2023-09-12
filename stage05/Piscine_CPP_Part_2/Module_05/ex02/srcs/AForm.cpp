/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:41:26 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 15:00:04 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("isNdef"), _signatureState(false), _gradeToSign(150), _gradeToExecute(150){
	return ;
}

AForm::AForm(std::string name, std::string target, int gradeToSign, int gradeToExecute) : _name(name), _target(target), _signatureState(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw GradeTooHighExeception();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw GradeTooLowExeception();
	return;
}

AForm::AForm(const AForm &obj) : _name(obj.getName()), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute()){
	*this = obj;
	return ;
}

AForm &AForm::operator=(const AForm &obj){
	if (this != &obj){
		this->_target = obj.getTarget();
		this->_signatureState = obj._signatureState;
	}
	return *this;
}

AForm::~AForm(){
	return ;
}

		std::string	AForm::getName()							const{
	return (this->_name);
}

		std::string	AForm::getTarget()							const{
	return (this->_target);
}

		bool		AForm::getSignatureState()				const{
	return (this->_signatureState);
}

		int			AForm::getGradeToSign()					const{
	return (this->_gradeToSign);
}

		int			AForm::getGradeToExecute()				const{
	return (this->_gradeToExecute);
}

		void		AForm::beSigned(const Bureaucrat &obj){
	if (obj.getGrade() > this->_gradeToSign)
		throw	GradeTooLowExeception();
	else
		this->_signatureState = true;
}

const	char*		AForm::GradeTooHighExeception::what()	const	throw(){
	return ("GradeTooHigh");
}

const	char*		AForm::GradeTooLowExeception::what()		const	throw(){
	return ("GradeTooLow");
}

const	char*		AForm::StatuSignatureExeception::what()		const	throw(){
	return ("StatuSignature is false");
}

std::ostream& operator<<(std::ostream& out, const AForm& obj){
    out << "AForm : " << obj.getName() << std::endl;
	out << std::left << std::setw(30) << "  is signed" << ": " << (obj.getSignatureState() ? "true" : "false") << std::endl;
	out << std::left << std::setw(30) << "  minimum grade to sign" << ": "  << obj.getGradeToSign() << std::endl;
	out << std::left << std::setw(30) << "  minimum grade to execute" << ": "  << obj.getGradeToExecute();
    return out;
}

