/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:37:28 by argomez           #+#    #+#             */
/*   Updated: 2023/03/24 11:25:58 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

# include	<iostream>
# include	<string>
# include	<exception>
# include	"AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const	std::string	_name;
		int					_grade;
		
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
		Bureaucrat ();
		Bureaucrat (std::string name, int grade);
		Bureaucrat (const Bureaucrat&);
		Bureaucrat &operator=(const Bureaucrat&);
		~Bureaucrat ();

		const	std::string	getName()			const;
				int			getGrade()			const;
				
					void	promote();
					void	demote();
					void	signForm(AForm &obj)			const;
					void	executeForm(AForm const & form)	const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif
