/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:09:28 by argomez           #+#    #+#             */
/*   Updated: 2023/02/22 14:34:23 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Contact::Contact(void){
	// std::cout << "Contact Constructor Called" << std::endl;
	return ;
}

Contact::~Contact(void){
	// std::cout << "Contact Destructor Called" << std::endl;
	return ;
}

void		Contact::addFirstName(std::string info){
	this->_firstName = info;
}

void		Contact::addLastName(std::string info){
	this->_lastName = info;
}

void		Contact::addNickName(std::string info){
	this->_nickName = info;
}

void		Contact::addPhoneNumber(std::string info){
	this->_phoneNumber = info;
}

void		Contact::addDarkestSecret(std::string info){
	this->_darkestSecret = info;
}

void		Contact::addContact(std::string infos[5]){
	addFirstName(infos[0]);
	addLastName(infos[1]);
	addNickName(infos[2]);
	addPhoneNumber(infos[3]);
	addDarkestSecret(infos[4]);
}

std::string	Contact::getFirstName(void){
	return (this->_firstName);
}

std::string	Contact::getLastName(void){
	return (this->_lastName);
}

std::string	Contact::getNickName(void){
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber(void){
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void){
	return (this->_darkestSecret);
}

void		Contact::getContact(std::string infos[5]){
	infos[0] = this->getFirstName();
	infos[1] = this->getLastName();
	infos[2] = this->getNickName();
	infos[3] = this->getPhoneNumber();
	infos[4] = this->getDarkestSecret();
}