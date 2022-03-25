/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:49:47 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/02/12 13:50:02 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_checker(va_list arguments, const char *c, int *i);

void	ft_check_width(const char *c, int *i)
{
	int	width;

	width = 0;
	while (*c >= '0' && *c <= '9')
	{
		width = width * 10 + (*c - 48);
		c++;
	}	
	while (width > 1)
	{
		write(1, " ", 1);
		width--;
		*i += 1;
	}
}

void	ft_format_checker(va_list arguments, const char *c, int *i)
{	
	if (*c == 'c')
		ft_putchar(va_arg(arguments, int), i);
	else if (*c == 's')
		ft_putstr(va_arg(arguments, char *), i);
	else if (*c == 'p')
		ft_putpointer(va_arg(arguments, void *), i);
	else if (*c == 'd')
		ft_putnbr(va_arg(arguments, int), i);
	else if (*c == 'i')
		ft_putnbr(va_arg(arguments, int), i);
	else if (*c == 'u')
		ft_putunbr(va_arg(arguments, int), i);
	else if (*c == 'x')
		ft_puthexa_low(va_arg(arguments, unsigned int), i);
	else if (*c == 'X')
		ft_puthexa_up(va_arg(arguments, unsigned int), i);
	else if (*c == '%')
	{
		*i += 1;
		write(1, "%", 1);
	}
	else
		ft_format_checker(arguments, c + 1, i);
}

int	ft_printf(const char *x, ...)
{
	va_list		arguments;
	int			counter;

	counter = 0;
	va_start(arguments, x);
	while (*x)
	{
		if (*x == '%')
		{
			ft_format_checker(arguments, (x + 1), &counter);
			x++;
		}
		else
		{
			write(1, x, 1);
			counter++;
		}
		x++;
	}
	va_end(arguments);
	return (counter);
}
