/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:09:32 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/04/13 12:03:58 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	unsigned char	b;

	b = 0b10000000;
	while (b)
	{
		if (b & c)
		{
			if (kill(pid, SIGUSR2))
				exit_error();
		}
		else
		{
			if (kill(pid, SIGUSR1))
				exit_error();
		}
		usleep(100);
		b >>= 1;
	}
}

void	print(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("received\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t	s_pid;
	int		i;

	i = 0;
	if (argc < 3)
		return (0);
	s_pid = ft_atoi(argv[1]);
	if (s_pid == 0)
		exit_error();
	signal(SIGUSR1, print);
	while (1)
	{	
		while (argv[2][i])
		{
			send_char(argv[2][i], s_pid);
			i++;
		}
		send_char(0, s_pid);
	}
	return (0);
}
