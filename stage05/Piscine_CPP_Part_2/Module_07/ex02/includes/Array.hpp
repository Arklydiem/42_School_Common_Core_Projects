/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:53:18 by argomez           #+#    #+#             */
/*   Updated: 2023/03/31 13:42:09 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ARRAY_HPP
# define	ARRAY_HPP

# include	<iostream>
# include	<exception>

template< class T >
class Array
{
	private:
		T*				_array;
		unsigned int	_size;
	protected:

	public:
		Array(/* args */);
		Array(unsigned int size);
		Array(const Array&);
		Array& operator=(const Array&);
		~Array();

		T& operator[](unsigned int index);
		unsigned int	size(void)	const;
};

template<class T>
Array<T>::Array(void) : _array(NULL), _size(0){
	return ;
}

template<class T>
Array<T>::Array(unsigned int size){
	this->_array = new T[size]();
	this->_size = size;
}

template<class T>
Array<T>::Array(const Array<T> &obj){
	this->_array = new T[obj._size];
	for (unsigned int i = 0; i < obj._size; i++)
	{
		this->_array[i] = obj._array[i];
	}
	this->_size = obj._size;
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &obj){
	if (this == &obj)
		return (*this);
	if (this->_array)
		delete this->_array;
	new (this) Array<T> (obj);
	return *this;
}

template<class T>
Array<T>::~Array(void){
	if (this->_array)
		delete [] this->_array;
	return ;
}

template<class T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size || index < 0) {
        throw std::exception();
    }
    return this->_array[index];
}

template<class T>
unsigned int	Array<T>::size(void) const{
	return (this->_size);
}

#endif