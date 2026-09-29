/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 23:15:15 by rexposit          #+#    #+#             */
/*   Updated: 2026/09/29 23:53:30 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void	print(const T &value)
{
	std::cout << value << std::endl;
}

template <typename T>
void	increment(T &value)
{
	value++;
}

int	main(void)
{
	int			numbers[] = {1, 2, 3, 4, 5};
	std::string	words[] = {"Hello", "from", "CPP07"};
	const int	const_numbers[] = {10, 20, 30};

	std::cout << "Numbers:" << std::endl;
	iter(numbers, 5, print<int>);

	std::cout << "\nIncremented numbers:" << std::endl;
	iter(numbers, 5, increment<int>);
	iter(numbers, 5, print<int>);

	std::cout << "\nStrings:" << std::endl;
	iter(words, 3, print<std::string>);

	std::cout << "\nConst numbers:" << std::endl;
	iter(const_numbers, 3, print<int>);

	return (0);
}