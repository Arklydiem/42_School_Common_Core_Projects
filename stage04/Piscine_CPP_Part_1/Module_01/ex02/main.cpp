/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:04:20 by argomez           #+#    #+#             */
/*   Updated: 2023/01/14 14:04:20 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){
    std::string		string = "HI THIS IS BRAIN";
    std::string*	stringPTR = &string;
    std::string&	stringREF(string);

    std::cout << "Adresse de String    = " << &string << std::endl;
    std::cout << "Adresse de StringPTR = " << stringPTR << std::endl;
    std::cout << "Adresse de StringREF = " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Valeur de String     = " << string << std::endl;
    std::cout << "Valeur de StringPTR  = " << *stringPTR << std::endl;
    std::cout << "valeur de StringREF  = " << stringREF << std::endl;
    return (0);
}