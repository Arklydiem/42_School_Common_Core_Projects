/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:13:53 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 14:23:24 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     SHRUBBERYCREATIONFORM_HPP
# define    SHRUBBERYCREATIONFORM_HPP

# include   "AForm.hpp"
# include	<fstream>

class ShrubberyCreationForm : virtual public AForm
{
    private:
	
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm (const ShrubberyCreationForm&);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
        ~ShrubberyCreationForm();

		void	execute(const Bureaucrat &obj)	const;
};


#endif