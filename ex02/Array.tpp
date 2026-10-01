/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 00:15:19 by rexposit          #+#    #+#             */
/*   Updated: 2026/09/30 01:03:19 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array()
{
	array = NULL;
	n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	array = new T[n];
	this->n = n;
}

template <typename T>
Array<T>::Array(const Array &other)
{
	this->n = other.n;
	this->array = new T[this->n];

	unsigned int	i;

	i = 0;
	while (i < this->n)
	{
		this->array[i] = other.array[i];
		i++;
	}
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);

	delete[] this->array;

	this->n = other.n;
	this->array = new T[this->n];

	unsigned int	i;

	i = 0;
	while (i < this->n)
	{
		this->array[i] = other.array[i];
		i++;
	}

	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= n)
		throw std::exception();
	else
		return (array[index]);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= n)
		throw std::exception();
	else
		return (array[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (n);
}
