/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:49:57 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/02/12 13:50:00 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *x, ...);
void	ft_putchar(int c, int *i);
void	ft_putstr(char *s, int *i);
void	ft_putunbr(unsigned int n, int *i);
void	ft_putnbr(int n, int *i);
void	ft_puthexa_up(unsigned long n, int *i);
void	ft_puthexa_low(unsigned long n, int *i);
void	ft_putpointer(void *n, int *i);

#endif