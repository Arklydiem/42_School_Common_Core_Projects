/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:07:45 by argomez           #+#    #+#             */
/*   Updated: 2023/04/17 18:55:08 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool isArgumentsValids(int argc, char* argv[]);

void	PmergeMe::run(int argc, char *argv[]){
	if (!isArgumentsValids(argc, argv))
		throw PmergeMe::ErrorException();

	std::vector<int>	intVector;
	double	processTimeVector = fillContainer(argv, intVector);
	
	std::deque<int>		intDeque;
	double	processTimeDeque  = fillContainer(argv, intDeque);
	
	std::cout << "Before : ";
	displayContainer(intVector);

	processTimeVector += mergeInsertSortVector(intVector);
	processTimeDeque += mergeInsertSortDeque(intDeque);

	std::cout << "After  : ";
	displayContainer(intVector);


	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << processTimeVector << " μs" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : " << processTimeDeque  << " μs" << std::endl;
}

/* ---------------------------------------- Sort Vector ----------------------------------------*/

void insertSortVector(std::vector<int>& intVector){
	size_t size = intVector.size();

	for (size_t i = 1; i < size; i++) {
		
		int tmp = intVector[i];
		int j = i - 1;

		while (j >= 0 && tmp < intVector[j]) {
			intVector[j + 1] = intVector[j];
			--j;
		}
   		intVector[j + 1] = tmp;
	}
}

void mergeSortVector(std::vector<int>& intVector){
	size_t sizeVector = intVector.size();
	if (sizeVector <= 15)
	{
		insertSortVector(intVector);
		return ;
	}
	
	std::vector<int> leftC (intVector.begin(), intVector.begin() + sizeVector / 2);
	size_t sizeLeftC = leftC.size();

	std::vector<int> rightC ((intVector.begin() + sizeVector / 2), intVector.end());
	size_t sizeRightC = rightC.size();

	mergeSortVector(leftC);
	mergeSortVector(rightC);

	size_t i = 0, j = 0, k = 0;
	while (j < sizeLeftC && k < sizeRightC)
	{
		if (leftC[j] <= rightC[k])
		{
			intVector[i] = leftC[j];
			i++, j++;
		}
		else if (leftC[j] > rightC[k])
		{
			intVector[i] = rightC[k];
			i++, k++;
		}
	}
	while (j < sizeLeftC){
		intVector[i] = leftC[j];
		i++, j++;
	}
	while (k < sizeRightC){
		intVector[i] = rightC[k];
		i++, k++;
	}
}

double	PmergeMe::mergeInsertSortVector(std::vector<int>& intVector){
	clock_t start;
	start = clock();

	mergeSortVector(intVector);

	clock_t end;
	end = clock();
	return (end - start);
}
/* ---------------------------------------- Sort Deque ----------------------------------------*/

void insertSortDeque(std::deque<int>& intDeque){
	size_t size = intDeque.size();

	for (size_t i = 1; i < size; i++) {
		
		int tmp = intDeque[i];
		int j = i - 1;

		while (j >= 0 && tmp < intDeque[j]) {
			intDeque[j + 1] = intDeque[j];
			--j;
		}
   		intDeque[j + 1] = tmp;		
	}
}

void mergeSortDeque(std::deque<int>& intDeque){
	size_t sizeDeque = intDeque.size();
	if (sizeDeque <= 15)
	{
		insertSortDeque(intDeque);
		return ;
	}


	std::deque<int> leftC (intDeque.begin(), intDeque.begin() + sizeDeque / 2);
	size_t sizeLeftC = leftC.size();

	std::deque<int> rightC ((intDeque.begin() + sizeDeque / 2), intDeque.end());
	size_t sizeRightC = rightC.size();

	mergeSortDeque(leftC);
	mergeSortDeque(rightC);

	size_t i = 0, j = 0, k = 0;
	while (j < sizeLeftC && k < sizeRightC)
	{
		if (leftC[j] <= rightC[k])
		{
			intDeque[i] = leftC[j];
			i++, j++;
		}
		else if (leftC[j] > rightC[k])
		{
			intDeque[i] = rightC[k];
			i++, k++;
		}
	}
	while (j < sizeLeftC){
		intDeque[i] = leftC[j];
		i++, j++;
	}
	while (k < sizeRightC){
		intDeque[i] = rightC[k];
		i++, k++;
	}
}

double	PmergeMe::mergeInsertSortDeque(std::deque<int>& intDeque){
	clock_t start;
	start = clock();

	mergeSortDeque(intDeque);

	clock_t end;
	end = clock();
	return (end - start);
}

/* ---------------------------------------- Others ----------------------------------------*/

static bool isArgumentsValids(int argc, char* argv[]){
	if (argc < 2)
		return (false);
		
	long int	value;
	char*		restValue;

	for (size_t i = 1; argv[i]; i++){
		if (!strlen(argv[i]) || strlen(argv[i]) > 11)
			return (false);
		value = strtol(argv[i], &restValue, 10);
		if (restValue[0] != '\0' || value < 0 || value > 2147483647)
			return (false);
	}
	return (true);
}

const char* PmergeMe::ErrorException::what() const throw(){
	return ("\e[38;5;196mError\e[0m");
}