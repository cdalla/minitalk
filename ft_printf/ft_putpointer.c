/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:50:27 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/02/12 13:50:34 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(void *n, int *i)
{
	unsigned long	addr;

	addr = (unsigned long) n;
	write(1, "0", 1);
	write(1, "x", 1);
	*i += 2;
	ft_puthexa_low(addr, i);
}
