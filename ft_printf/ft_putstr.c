/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:50:30 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/02/12 13:50:32 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *i)
{
	if (s)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
			*i += 1;
		}
	}
	else
		ft_putstr("(null)", i);
}
