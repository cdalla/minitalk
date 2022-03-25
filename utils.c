/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:09:49 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/03/25 11:09:49 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
		index++;
	return (index);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	num;
	int	sign;

	index = 0;
	num = 0;
	sign = 1;
	while (str[index] == '\t' || str[index] == '\v' || str[index] == '\f'
		|| str[index] == '\r' || str[index] == '\n' || str[index] == ' ')
		index++;
	if (str[index] == '-')
	{
		sign = -sign;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		num = num * 10 + (str[index] - 48);
		index++;
	}
	return (num * sign);
}
