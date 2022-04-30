/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 16:23:34 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/04/13 11:32:34 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define BUFFER_SIZE 201

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_message
{
	unsigned char		c;
	int					buff_i;
	int					bit_i;
	int					client_pid;
	struct sigaction	new;
	char				message[BUFFER_SIZE];
}				t_message;

//UTILS
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	print_message(void);
void	loop(void);
void	exit_error(void);

//SERVER
void	sig_handler_info(int signum, siginfo_t *info, void *ucontext);
void	add_char(char ch);

//CLIENT
void	send_char(char c, int pid);
void	print(int signum);

#endif