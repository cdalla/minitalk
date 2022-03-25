/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:50:23 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/02/12 13:50:24 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long	i;

	i = n;
	if (i < 0)
	{
		write(1, "-", 1);
		i = i * -1;
		*count += 1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10, count);
		i = i % 10 + 48;
		write(1, &i, 1);
		*count += 1;
	}
	else
	{
		i = i + 48;
		write(1, &i, 1);
		*count += 1;
	}
}
