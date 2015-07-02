/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 14:50:01 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/25 17:48:56 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	public:
		Span(unsigned int N);
		Span();
		Span(Span const & src);
		~Span();

		Span & operator=(Span const & rhs);

		void	addNumber(int add);

		void	addNumber(int *nb, unsigned int const &size);

		int		longestSpan();
		int		shortestSpan();

		class FullException : public std::exception
		{
			const char * what() const throw()
			{ return "Max size already reached"; }
		};

		class NoSpanException : public std::exception
		{
			const char * what() const throw()
			{ return "Not engouh number stored to search span."; }
		};

	private:
		std::vector<int>	_vec;
		unsigned int		_lenMax;

};

#endif
