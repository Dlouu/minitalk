/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:08:01 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/28 15:39:43 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/minitalk.h"

/* alternatives for struct init :
	*data = (t_data){.bit = 0, .c = 0, .i = 0, .len = 0};
	*data = (t_data){0}; */
static void	ctrl_c_handler(t_data *data, char **str, int pid)
{
	static int	client_pid;

	if (pid != client_pid)
	{
		client_pid = pid;
		if (*str)
		{
			free(*str);
			*str = NULL;
		}
		data->bit = 0;
		data->c = 0;
		data->i = 0;
		data->len = 0;
	}
}

/* alternatives for incrementing bit :
	if (signal == SIGUSR1)
		len /= 1 << bit;
	bit += 1;
or
	c += (signal == SIGUSR1) << bit++; */
static void	set_len(int signal, t_data *data, char **str, int client_pid)
{
	data->len += (signal == SIGUSR1) << data->bit++;
	if (data->bit == LEN_WIDTH)
	{
		data->bit = 0;
		*str = (char *)malloc(sizeof(char) * (data->len + 2));
		if (!*str)
			ft_error(ERR_MALLOC);
		clean_kill(SIGUSR2, client_pid);
	}
	else
		clean_kill(SIGUSR1, client_pid);
}

static void	end_of_message(t_data *data, char **str, int client_pid)
{
	(*str)[data->i] = '\n';
	(*str)[data->i + 1] = '\0';
	ft_putstr(*str);
	free(*str);
	*str = NULL;
	data->i = 0;
	data->len = 0;
	clean_kill(SIGUSR2, client_pid);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static t_data	data;
	static char		*str = NULL;

	(void)context;
	ctrl_c_handler(&data, &str, info->si_pid);
	if (str == NULL)
		set_len(signal, &data, &str, info->si_pid);
	else
	{
		data.c += (signal == SIGUSR1) << data.bit++;
		if (data.bit == 8)
		{
			str[data.i++] = data.c;
			data.bit = 0;
			data.c = 0;
		}
		if (data.i == data.len)
			end_of_message(&data, &str, info->si_pid);
		else
			clean_kill(SIGUSR1, info->si_pid);
	}
}

int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	ft_printf("Server connected, PID is %d\n \
	to send a message please type :\n \
	./client %d \"message\"\n", server_pid, server_pid);
	set_signal(SIGUSR1, signal_handler);
	set_signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

/* RANDOM NOTES :
sa_mask = masque de signaux a bloquer
sigaddset (ajouter un signal au masque) != sigemptyset (vide tous les masques)
set = signaux de base
sa_flags = SA_SIGINFO permet d'avoir le prototype (int, siginfo_t *, void *)
d'utiliser les infos siginfo_t dans le man sigaction */

/* A AMELIORER :
multiple clients en meme temps, bloquer le client si le serveur est busy
leak coté serveur si erreur de kill/sigaction ? */