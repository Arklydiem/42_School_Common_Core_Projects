/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:05:11 by argomez           #+#    #+#             */
/*   Updated: 2023/04/17 18:54:49 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PMERGEME_HPP
# define	PMERGEME_HPP

# include	<iostream>
# include	<iomanip>
# include	<exception>
# include	<cstdlib>
# include	<cstring>
# include	<vector>
# include	<deque>
# include	<ctime>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		~PmergeMe();

		template<class Tcontainer>
		static double	fillContainer(char *argv[], Tcontainer& container);
		template<class Tcontainer>
		static void		displayContainer(Tcontainer& container);

		static double	mergeInsertSortVector(std::vector<int>& container);
		static double	mergeInsertSortDeque(std::deque<int>& container);
		
	protected:

	public:
		static void	run(int argc, char *argv[]);
		class ErrorException : public std::exception{
			public :
				virtual const char* what() const throw();
		};
};

template<class Tcontainer>
double PmergeMe::fillContainer(char *argv[], Tcontainer& container){
	clock_t start;
	start = clock();

	int value;
	for (size_t i = 1; argv[i]; i++){
		value = strtol(argv[i], NULL, 10);
		container.push_back(value);
	}

	clock_t end;
	end = clock();
	return (end - start);
}

template<class Tcontainer>
void PmergeMe::displayContainer(Tcontainer &container){
	size_t size = container.size();
	for (size_t i = 0; i < size; i++){
		std::cout << container[i];
		if (i < size - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}


#endif