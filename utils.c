/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:09:49 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/04/07 15:50:29 by cdalla-s      ########   odam.nl         */
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

	index = 0;
	num = 0;
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			num = num * 10 + (str[index] - 48);
		else
			return (0);
		index++;
	}
	return (num);
}

void	exit_error(void)
{
	ft_printf("ERROR\n");
	exit(0);
}
