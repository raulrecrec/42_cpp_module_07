/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 23:31:40 by rexposit          #+#    #+#             */
/*   Updated: 2026/09/30 00:20:56 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void	iter(T *array, const size_t len, F f)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		f(array[i]);
		i++;
	}
}

#endif