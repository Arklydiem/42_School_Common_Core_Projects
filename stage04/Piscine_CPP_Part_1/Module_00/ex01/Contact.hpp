/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:08:16 by argomez           #+#    #+#             */
/*   Updated: 2023/01/11 13:25:59 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

#ifndef		CONTACT_CLASS_HPP
# define	CONTACT_CLASS_HPP

class Contact
{
    public:
        Contact		(); // Constructeur par défaut
        ~Contact	(); // Destructeur éventuellement virtuel

		//Adding a new contact
		void		addFirstName(std::string info);
		void		addLastName(std::string info);
		void		addNickName(std::string info);
		void		addPhoneNumber(std::string info);
		void		addDarkestSecret(std::string info);
		void		addContact(std::string infos[5]);

		//Get informations
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
		void		getContact(std::string infos[5]);
		
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
	
};

#endif