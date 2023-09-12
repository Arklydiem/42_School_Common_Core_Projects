/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:16:27 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:32:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"

#include "./WrongAnimal.hpp"
#include "./WrongCat.hpp"

int main(void)
{
	{
		Animal	creature;
		Animal	monster("Monster");
		Animal	myth = monster;
		Animal	other(myth);
	}
	std::cout << std::endl;
	{		
		const Animal* meta = new Animal();
		const Animal* i = new Cat();

		std::cout << i->getType() << " " << std::endl;
		
		i->makeSound(); //will output the cat sound!
		meta->makeSound();

		delete i;
		delete meta;
	}
	std::cout << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* i = new Dog();

		std::cout << i->getType() << " " << std::endl;
		
		i->makeSound(); //will output the dog sound!
		meta->makeSound();

		delete i;
		delete meta;
	}
	std::cout << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete i;
		delete j;
		delete meta;
	}

	std::cout << std::endl ;

	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		i->makeSound();
		meta->makeSound();
		
		delete i;
		delete meta;
	}
	return 0;
}
