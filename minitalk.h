/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 16:23:34 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/04/07 12:50:32 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_message
{
	unsigned char		c;
	int					i;
	int					index;
	int					c_pid;
	struct sigaction	new;
	char				message[201];
}				t_message;

//UTILS
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	print_message(void);
void	loop(void);

//SERVER
void	sig_handler_info(int signum, siginfo_t *info, void *ucontext);
void	add_char(char ch);

//CLIENT
void	send_char(char c, int pid);
void	print(int signum);

#endif