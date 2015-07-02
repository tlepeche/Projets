/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 14:58:08 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/25 17:48:43 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(void) : _vec(0), _lenMax(0) {}

Span::Span(unsigned int N) : _vec(0), _lenMax(N) {}

Span::Span(Span const & src) {
	this->_lenMax = src._lenMax;
	this->_vec = src._vec;
}

Span::~Span() {}

void	Span::addNumber(int add) {
	if (this->_vec.size() < this->_lenMax)
		(this->_vec).push_back(add);
	else
		throw Span::FullException();
}

void	Span::addNumber(int *nb, unsigned int const & size) {

	unsigned int i = 0;
	while (i < size)
	{
		if (this->_vec.size() < this->_lenMax)
			(this->_vec).push_back(nb[i]);
		else
			throw Span::FullException();
	i++;
	}
}

Span &	Span::operator=(Span const & rhs) {
	this->_vec = rhs._vec;
	this->_lenMax = rhs._lenMax;
	return *this;
}


int	Span::longestSpan() {
	if (this->_vec.size() > 1)
	{
		std::vector<int>::iterator		min;
		std::vector<int>::iterator		max;
		int		res;

		min = std::min_element(this->_vec.begin(), this->_vec.end());
		max = std::max_element(this->_vec.begin(), this->_vec.end());
		res = *max - *min;
		return res;
	}
	else
		throw Span::NoSpanException();
}

int	Span::shortestSpan() {
	unsigned int	i = 0;
	int				res = this->longestSpan();

	std::sort(this->_vec.begin(), this->_vec.end());
	while (i < this->_vec.size() - 1)
	{
		if (this->_vec[i + 1] - this->_vec[i] < res )
			res = this->_vec[i + 1] - this->_vec[i];
		i++;
	}

	return res;
}
