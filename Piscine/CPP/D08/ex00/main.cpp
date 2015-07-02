/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 13:48:59 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/25 14:48:33 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main (void)
{
	std::list<int>		lst;

	lst.push_back(10);
	lst.push_back(14);
	lst.push_back(29);
	lst.push_back(74);
	lst.push_back(42);
	lst.push_back(99);

	std::list<int>::const_iterator test;

	test = easyfind(lst, 42);
	if (test != lst.end())
		std::cout << "TROUVE" <<  std::endl;
	else
		std::cout << "PAS TROUVE" <<std::endl;
	return 0;
}
