/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:19:01 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/24 20:14:41 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./../libft/inc/libft.h"
# include <signal.h>

# define ERR_SIGACTION "Sigaction failure"
# define ERR_KILL "Kill failure"
# define ERR_MALLOC "Malloc failure"
# define LEN_WIDTH 64

typedef struct s_data
{
	char	bit;
	char	c;
	size_t	i;
	size_t	len;
}	t_data;

void	set_signal(int signum, void (*handler)(int, siginfo_t *, void *));
void	clean_kill(int signum, int pid);
void	bit_receipt(int signal, siginfo_t *info, void *context);
void	end_receipt(int signal, siginfo_t *info, void *context);
int		ft_error(char *error);

#endif
