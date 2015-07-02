/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 17:36:29 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/25 21:35:31 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
			public:
				iterator();
				iterator(iterator const & src);
				~iterator();

				iterator	&operator=(iterator const & rhs);
				iterator	&operator++();
				iterator	operator++(int);
				iterator	&operator--();
				iterator	operator--(int);
				T			operator*();
				bool		operator!=(iterator const & rhs) const;

				void		setPtr(T *ptr);

			private:
				T		*_ptr;
		};

		iterator	begin();
		iterator	end();

};

#include "mutantstack.cpp"

#endif
