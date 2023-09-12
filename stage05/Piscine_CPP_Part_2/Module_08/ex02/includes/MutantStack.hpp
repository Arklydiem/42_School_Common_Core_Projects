/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:53:18 by argomez           #+#    #+#             */
/*   Updated: 2023/04/07 10:12:14 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MUTANSTACK_HPP
# define	MUTANSTACK_HPP

# include	<deque>
# include	<stack>
# include	<iostream>

template <typename T, class CONTAINER = std::deque<T> >
class MutantStack : public std::stack<T>
{
	private:

	protected:
		
	public:
		MutantStack(){}
		MutantStack(const MutantStack& obj){
			*this = obj;
		}
		MutantStack& operator=(const MutantStack& obj){
			*this = obj;
			return *this;
		}
		~MutantStack(){}

		typedef typename CONTAINER::iterator iterator;

		iterator	begin(){
			return (this->c.begin());
		}
		iterator	end(){
			return (this->c.end());
		}
};

#endif
	