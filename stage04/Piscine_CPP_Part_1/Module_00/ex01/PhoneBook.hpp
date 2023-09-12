/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:18:11 by argomez           #+#    #+#             */
/*   Updated: 2023/01/12 09:48:11 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
// #include "Contact.class.hpp"

#ifndef		PHONEBOOK_CLASS_HPP
# define	PHONEBOOK_CLASS_HPP

class PhoneBook
{
    public:
        PhoneBook	(); // Constructeur par défaut
        ~PhoneBook	(); // Destructeur éventuellement virtuel
		void		add(void);
		void		search(int index);
		void		displayRepertory(void);
		
	private:
		Contact		_contacts[8];
		int			_contactsNumber;

};

#endif