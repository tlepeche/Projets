/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 17:36:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/25 22:04:14 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::iterator::iterator(void) : _ptr(NULL) {}


template <typename T>
MutantStack<T>::iterator::iterator(MutantStack<T>::iterator const & src) {
	*this = src;
}

template <typename T>
MutantStack<T>::iterator::~iterator() {}

/// OPERATORS ///
template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(typename MutantStack<T>::iterator const & rhs) {
	this->_ptr = rhs._ptr;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	&MutantStack<T>::iterator::operator++() {
	std::advance(this->_ptr, -1);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator++(int) {
	typename MutantStack<T>::iterator tmp(*this);
	operator++();
	return tmp;
}

template <typename T>
typename MutantStack<T>::iterator	&MutantStack<T>::iterator::operator--() {
	std::advance(this->_ptr, 1);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator--(int) {
	typename MutantStack<T>::iterator tmp(*this);
	operator--();
	return tmp;
}

template <typename T>
bool	MutantStack<T>::iterator::operator!=(MutantStack<T>::iterator const & rhs) const {
	return (this->_ptr != rhs._ptr);
}

template <typename T>
T		MutantStack<T>::iterator::operator*() {
	return *this->_ptr;
}

/// FUNCTIONS ///
template <typename T>
typename   MutantStack<T>::iterator	MutantStack<T>::end() {
	typename MutantStack< T >::iterator it;

	it.setPtr(&this->top());
	std::advance( it, this->size());
	return it;
}

template <typename T>
typename   MutantStack<T>::iterator	MutantStack<T>::begin() {
	typename MutantStack<T>::iterator it;

	it.setPtr(&this->top());
	return it;
}

template <typename T>
void	MutantStack<T>::iterator::setPtr(T *ptr) {
	this->_ptr = ptr;
}
