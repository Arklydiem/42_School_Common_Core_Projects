/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:32:29 by argomez           #+#    #+#             */
/*   Updated: 2023/03/29 17:29:52 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"A.hpp"
#include	"B.hpp"
#include	"C.hpp"
#include	<cstdlib>
#include	<cctype>
#include	<iostream>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int main(void)
{
	Base	*tryBase;
	
	for (size_t i = 0; i < 3; i++)
	{
		tryBase = generate();
		identify(tryBase);
		identify(*tryBase);
		delete tryBase;
	}
	
	return 0;
}

Base*	generate(void){
	srand(time(0));
	switch (rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}	
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "With * : It's an A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "With * : It's a B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "With * : It's a C" << std::endl;
}

void	identify(Base& p){
	if (dynamic_cast<A*>(&p))
		std::cout << "With & : It's an A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "With & : It's a B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "With & : It's a C" << std::endl;
}