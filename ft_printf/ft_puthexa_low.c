/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexa_low.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:50:11 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/02/12 13:50:12 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	static	ft_size(unsigned long n)
{
	int	size;

	size = 0;
	if (n == 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 16;
	}
	return (size);
}

void	ft_puthexa_low(unsigned long n, int *i)
{
	char	*base;
	char	*itoa;
	int		index;
	int		size;

	base = "0123456789abcdef";
	index = 0;
	size = ft_size(n);
	itoa = (char *)malloc(size * sizeof(char) + 1);
	if (!itoa)
		write(1, "ERROR", 5);
	itoa[size] = '\0';
	while (size > index || n > 0)
	{
		size--;
		itoa[size] = base[n % 16];
		n = n / 16;
	}
	ft_putstr(itoa, i);
	free(itoa);
}
