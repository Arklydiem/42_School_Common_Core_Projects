/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:41:26 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 14:59:44 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("<isNdef>"), _signatureState(false), _gradeToSign(150), _gradeToExecute(150){
	return ;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signatureState(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw GradeTooHighExeception();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw GradeTooLowExeception();
	return;
}

Form::Form(const Form &obj) : _name(obj.getName()), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute()){
	*this = obj;
	return ;
}

Form &Form::operator=(const Form &obj){
	if (this != &obj){
		this->_signatureState = obj._signatureState;
	}
	return *this;
}

Form::~Form(){
	return ;
}

		std::string	Form::getName()							const{
	return (this->_name);
}

		bool		Form::getSignatureState()				const{
	return (this->_signatureState);
}

		int			Form::getGradeToSign()					const{
	return (this->_gradeToSign);
}

		int			Form::getGradeToExecute()				const{
	return (this->_gradeToExecute);
}

		void		Form::beSigned(const Bureaucrat &obj){
	if (obj.getGrade() > this->_gradeToSign)
		throw	GradeTooLowExeception();
	else
		this->_signatureState = true;
}

const	char*		Form::GradeTooHighExeception::what()	const	throw(){
	return ("GradeTooHigh");
}

const	char*		Form::GradeTooLowExeception::what()		const	throw(){
	return ("GradeTooLow");
}

std::ostream& operator<<(std::ostream& out, const Form& obj){
    out << "Form : " << obj.getName() << std::endl;
	out << std::left << std::setw(30) << "  is signed" << ": " << (obj.getSignatureState() ? "true" : "false") << std::endl;
	out << std::left << std::setw(30) << "  minimum grade to sign" << ": "  << obj.getGradeToSign() << std::endl;
	out << std::left << std::setw(30) << "  minimum grade to execute" << ": "  << obj.getGradeToExecute();
    return out;
}

