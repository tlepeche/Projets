/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 13:48:57 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/25 14:46:29 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <list>

template <class T>
typename T::iterator	easyfind(T a, int b)
{
	typename T::iterator test;

	test = find(a.begin(), a.end(), b);
	return test;
}

#endif
