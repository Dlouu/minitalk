/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:15:27 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/28 15:39:35 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/minitalk.h"

void	clean_kill(int signum, int pid)
{
	if (kill(pid, signum) == -1)
		ft_error(ERR_KILL);
}

int	ft_error(char *error)
{
	ft_printf("Error : %s\n", error);
	exit(EXIT_FAILURE);
}

//permet de laisser le processeur process en redirigeant le signal
//dans un signal handler sinon le usleep n'est pas interrompu
void	bit_receipt(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	(void)signal;
}

void	end_receipt(int signal, siginfo_t *info, void *context)
{
	static int	awaiting_for_len = 1;

	(void)info;
	(void)context;
	(void)signal;
	if (awaiting_for_len)
		awaiting_for_len = 0;
	else
	{
		ft_putstr("Message sent\n");
		awaiting_for_len = 1;
	}
}

void	set_signal(int signum, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	signal;

	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = handler;
	if (sigaction(signum, &signal, NULL) == -1)
		ft_error(ERR_SIGACTION);
}
