/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 15:27:19 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/25 17:48:31 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
	Span sp = Span(2000);
	srand(time(0));
	int i = 0;
	while (i < 2001)
	{
		try
		{
			sp.addNumber(std::rand());
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		i++;
	}
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl ;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Span p2 = Span(3);
	int num[] = {1, 3, 5, 7, 10};
	try
	{
		p2.addNumber(num, 5);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Span p3 = Span(3);
	try
	{
		p3.addNumber(4);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl ;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

}
