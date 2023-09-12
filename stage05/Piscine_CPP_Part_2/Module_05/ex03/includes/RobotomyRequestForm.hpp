/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:17:17 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 14:23:22 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ROBOTOMYREQUESTFORM_HPP
# define	ROBOTOMYREQUESTFORM_HPP

# include	"AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
	private:
	
	public:
		RobotomyRequestForm(/* args */);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
		~RobotomyRequestForm();

		void	execute(const Bureaucrat &obj) const;
};

#endif