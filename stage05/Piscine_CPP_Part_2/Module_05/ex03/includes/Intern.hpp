/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:26:19 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 11:28:56 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class Intern
{
	private:

	protected:

	public:
		Intern();
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& obj);
		~Intern();

		AForm*	makeForm(std::string name, std::string target) const;
};
