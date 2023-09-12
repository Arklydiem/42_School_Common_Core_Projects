/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:20:30 by argomez           #+#    #+#             */
/*   Updated: 2023/03/16 16:41:41 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"
#include <iomanip>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void) {

	Point	t1(3.0f, 2.0f);
	Point	t2(7, 7);
	Point	t3(11, 4);
	Point	p1(7, 4);
	Point	p2(0, 0);
	Point	p3(9, 0);

	std::cout << (bsp(t1, t2, t3, p1) == 1 ? "TRUE" : "FALSE") << std::endl;
	std::cout << (bsp(t1, t2, t3, p2) == 1 ? "TRUE" : "FALSE") << std::endl;
	std::cout << (bsp(t1, t2, t3, p3) == 1 ? "TRUE" : "FALSE") << std::endl;
	
	return 0;
}