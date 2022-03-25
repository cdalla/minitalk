/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:50:38 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/02/12 13:50:39 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n, int *count)
{
	long	i;

	i = n;
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
