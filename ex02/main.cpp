/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 00:05:05 by rexposit          #+#    #+#             */
/*   Updated: 2026/09/30 01:05:53 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	Array<int>	numbers(5);

	std::cout << "Size: " << numbers.size() << std::endl;

	unsigned int	i;

	i = 0;
	while (i < numbers.size())
	{
		numbers[i] = i * 10;
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
		i++;
	}

	std::cout << "\nCopy constructor:" << std::endl;

	Array<int>	copy(numbers);

	copy[0] = 42;

	std::cout << "Original: " << numbers[0] << std::endl;
	std::cout << "Copy: " << copy[0] << std::endl;

	std::cout << "\nAssignment operator:" << std::endl;

	Array<int>	assigned;

	assigned = numbers;
	assigned[1] = 84;

	std::cout << "Original: " << numbers[1] << std::endl;
	std::cout << "Assigned: " << assigned[1] << std::endl;

	std::cout << "\nString array:" << std::endl;

	Array<std::string>	words(3);

	words[0] = "CPP";
	words[1] = "Module";
	words[2] = "07";

	i = 0;
	while (i < words.size())
	{
		std::cout << words[i] << std::endl;
		i++;
	}

	std::cout << "\nOut of bounds:" << std::endl;

	try
	{
		std::cout << numbers[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught" << std::endl;
	}
}