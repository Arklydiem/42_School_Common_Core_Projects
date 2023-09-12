/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:41:33 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 14:12:27 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FORM_HPP
# define	FORM_HPP

# include	<iostream>
# include	<iomanip>
# include	<string>
# include	<exception>
# include	"Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const	std::string		_name;
				bool			_signatureState;
		const	int				_gradeToSign;
		const	int				_gradeToExecute;
		
		class	GradeTooHighExeception	: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowExeception	: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	protected:
		
	public:
		Form ();
		Form (std::string name, int gradeToSign, int gradeToExecute);
		Form (const Form&);
		Form &operator=(const Form&);
		~Form ();

				std::string		getName() 			const;
				bool			getSignatureState()	const;
				int				getGradeToSign()	const;
				int				getGradeToExecute()	const;

				void			beSigned(const Bureaucrat	&obj);
};

std::ostream& operator<<(std::ostream& out, const Form& obj);


#endif
