/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:16:27 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:53:20 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"

#include "./WrongAnimal.hpp"
#include "./WrongCat.hpp"

int main()
{
    {
        std::cout << std::endl << std::endl << "------- BASIC TEST -------" << std::endl << std::endl;

        const Animal* array[10];
        for (int i = 0; i < 10; i++)
        {
            if (i % 2 == 0)
            {
                array[i] = new Dog();
                array[i]->getBrain()->setIdea("First");

            }
            else
            {
                array[i] = new Cat();
                array[i]->getBrain()->setIdea("Second");
            }
        }
        std::cout << std::endl;
        for (int i = 0; i < 10; i++)
        {
            std::cout << array[i]->getType() << std::endl;
            array[i]->showBrain(5);
        }
        std::cout << std::endl << std::endl << "------- SET BRAIN INVALID TEST -------" << std::endl << std::endl;
        array[0]->getBrain()->setIdea("Invalid");
        array[0]->getBrain()->setIdea("Invalid");
        array[0]->showBrain(5);
        array[0]->showBrain(-1);
        std::cout << std::endl;
        std::cout << "\033[0;31m------- Deleting objects ------- \033[0m " << std::endl;
        for (int i = 0; i < 10; i++)
            delete array[i];
        std::cout << std::endl;
    }
	{
        std::cout << std::endl << std::endl << "------- DEEP COPY TEST -------" << std::endl << std::endl;
        Cat* h = new Cat();
        h->getBrain()->setIdea("First");
        Cat* k = new Cat(*h);
        std::cout << std::endl;
        h->showBrain(5);
        k->showBrain(5);
		std::cout << std::endl;
        h->getBrain()->setIdea("Second");
        h->showBrain(5);
        k->showBrain(5);
        std::cout << std::endl;
        *k = *h;
        h->showBrain(5);
        k->showBrain(5);
		std::cout << std::endl;
        h->getBrain()->setIdea("First");
        h->showBrain(5);
        k->showBrain(5);
		std::cout << std::endl;
        std::cout << "\033[0;31m------- Deleting objects ------- \033[0m " << std::endl;
        delete h;
        delete k;
        std::cout << std::endl;
    }

    return (0);
}