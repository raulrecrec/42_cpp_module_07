/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 00:04:58 by rexposit          #+#    #+#             */
/*   Updated: 2026/10/01 15:47:26 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class	Array
{
	private:
		T				*array;
		unsigned int	n;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array	&operator=(const Array &other);
		~Array();

		T			&operator[](unsigned int index);
		const T		&operator[](unsigned int index) const;
		unsigned int	size() const;
};

#include "Array.tpp"

#endif
