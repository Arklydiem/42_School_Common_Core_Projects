/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:03:28 by argomez           #+#    #+#             */
/*   Updated: 2023/02/06 23:20:25 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

PhoneBook::PhoneBook(void){
	// std::cout << "PhoneBook Constructor Called" << std::endl;
	this->_contactsNumber = 0;
	return ;
}

PhoneBook::~PhoneBook(void){
	// std::cout << "PhoneBook Destructor Called" << std::endl;
	return ;
}

void	getInfos(std::string infos[5]){

	std::string	toPrint[] = {"FirstName",
								"LastName",
								"NickName",
								"PhoneNumber",
								"DarkestSecret"};
	
	for (size_t index = 0; index < 5; index++)
	{
		while (infos[index].empty())
		{
			std::cout << std::left << std::setw(15) << toPrint[index] << "\e[1;36m ➔ \e[0;0m";
			std::getline(std::cin, infos[index]);
			if (std::cin.eof())

			if (infos[index].empty())
				break ;
		}
		if (std::cin.eof() && infos[index].empty())
			break ;
	}
	std::cout << std::endl;
}

void	PhoneBook::add(void){
	std::string	infos[5];

	std::cout << "Adding a new Contact \n" << std::endl;

	getInfos(infos);

	if (this->_contactsNumber < 8)
	{
		this->_contacts[_contactsNumber].addContact(infos);
		this->_contactsNumber++;
	}
	else
	{
		for (size_t i = 0; i < 7; i++)
			this->_contacts[i] = this->_contacts[i + 1];
		this->_contacts[7].addContact(infos);
	}
}

void	PhoneBook::displayRepertory(void){
	std::string	infos[5];

	std::cout << std::right << "\e[0;95m|\e[0;37m"
		<< "\e[0;93m" << std::setw(10) << "Index" << "\e[0;95m|\e[0;37m"
		<< "\e[0;93m" << std::setw(10) << "First Name" << "\e[0;95m|\e[0;37m"
		<< "\e[0;93m" << std::setw(10) << "Last Name" << "\e[0;95m|\e[0;37m"
		<< "\e[0;93m" << std::setw(10) << "Nick Name" << "\e[0;95m|\e[0;37m"
		<< std::endl;

	for (size_t index = 0; index < 8; index++)
	{
		this->_contacts[index].getContact(infos);
		std::cout << "\e[0;95m|\e[0;37m" << std::setw(10) << index;
		for (size_t i = 0; i < 3; i++)
		{
			if (infos[i].length() <= 10)
				std::cout << "\e[0;95m|\e[0;33m" << std::setw(10) << infos[i];
			else
				std::cout << "\e[0;95m|\e[0;33m" << std::setw(9) << infos[i].substr(0, 9) << "\e[93m.";
		}
		std::cout << "\e[0;95m|\e[0;0m" << std::endl;
	}
}

void	PhoneBook::search(int index){
	std::string	infos[5];

	this->_contacts[index].getContact(infos);
	std::cout	<< std::left << std::setw(15) << "First Name" << "\e[1;36m ➔ \e[0;0m" << infos[0] << std::endl
				<< std::left << std::setw(15) << "Last Name" << "\e[1;36m ➔ \e[0;0m" << infos[1] << std::endl
				<< std::left << std::setw(15) << "Nick Name" << "\e[1;36m ➔ \e[0;0m" << infos[2] << std::endl
				<< std::left << std::setw(15) << "Phone Number" << "\e[1;36m ➔ \e[0;0m" << infos[3] << std::endl
				<< std::left << std::setw(15) << "Darkest Secret" << "\e[1;36m ➔ \e[0;0m" << infos[4] << std::endl
				<< std::endl;
}