/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:25:12 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 14:23:19 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PRESIDENTIALPARDONFORM_HPP
# define	PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
	private:
	
	public:
		PresidentialPardonForm(/* args */);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		~PresidentialPardonForm();

		void	execute(const Bureaucrat &obj) const;
};

#endif