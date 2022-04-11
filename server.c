/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:09:27 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/04/07 15:51:04 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"	

t_message	g_str;

void	sig_handler_info(int signum, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	g_str.c <<= 1;
	if (signum == SIGUSR2)
		g_str.c |= 1;
	g_str.index += 1;
	g_str.c_pid = info->si_pid;
}

void	print_message(void)
{
	g_str.message[g_str.i] = '\0';
	write(1, g_str.message, ft_strlen(g_str.message));
	g_str.i = -1;
}

void	loop(void)
{
	if (sigaction(SIGUSR1, &g_str.new, NULL))
		exit_error();
	if (sigaction(SIGUSR2, &g_str.new, NULL))
		exit_error();
	if (g_str.index == 8)
	{	
		if (g_str.c == 0)
		{
			print_message();
			write(1, "\n", 1);
			if (kill(g_str.c_pid, SIGUSR1))
				exit_error();
		}
		if (g_str.i < 200 && g_str.c != 0)
			g_str.message[g_str.i] = g_str.c;
		if (g_str.i == 200)
			print_message();
		g_str.i += 1;
		g_str.c = 0;
		g_str.index = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	g_str.new.sa_sigaction = sig_handler_info;
	g_str.i = 0;
	g_str.index = 0;
	g_str.c = 0;
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
		loop();
	return (0);
}
