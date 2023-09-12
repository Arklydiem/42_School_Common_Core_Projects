/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:41:33 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 14:32:58 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AFORM_HPP
# define	AFORM_HPP

# include	<iostream>
# include	<iomanip>
# include	<string>
# include	<exception>
# include	"Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const	std::string		_name;
				std::string		_target;
				bool			_signatureState;
		const	int				_gradeToSign;
		const	int				_gradeToExecute;
		

	protected :
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
		
		class	StatuSignatureExeception: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	protected:
		
	public:
		AForm ();
		AForm (std::string name, std::string target, int gradeToSign, int gradeToExecute);
		AForm (const AForm&);
		AForm &operator=(const AForm&);
		virtual ~AForm ();

				std::string		getName() 			const;
				std::string		getTarget()			const;
				bool			getSignatureState()	const;
				int				getGradeToSign()	const;
				int				getGradeToExecute()	const;

				void			beSigned(const Bureaucrat	&obj);
		virtual	void			execute(const Bureaucrat	&obj)	const	= 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);


#endif
