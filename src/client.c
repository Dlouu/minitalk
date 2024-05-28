/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:08:01 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/27 15:03:02 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/minitalk.h"

static void	send_len(int server_pid, size_t len)
{
	int	bit;

	bit = 0;
	while (bit < LEN_WIDTH)
	{
		bit++;
		if (len & 1)
		{
			clean_kill(SIGUSR1, server_pid);
			usleep(100);
		}
		else
		{
			clean_kill(SIGUSR2, server_pid);
			usleep(100);
		}
		len >>= 1;
		usleep(42);
	}
}

static void	send_message(int server_pid, char *str)
{
	int		bit;
	char	c;

	while (*str)
	{
		bit = 0;
		c = *str;
		while (bit < 8)
		{
			bit++;
			if (c & 1)
			{
				clean_kill(SIGUSR1, server_pid);
				usleep(100);
			}
			else
			{
				clean_kill(SIGUSR2, server_pid);
				usleep(100);
			}
			c >>= 1;
			usleep(42);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;
	size_t	len;

	if (argc != 3)
		return (EXIT_FAILURE);
	set_signal(SIGUSR1, &bit_receipt);
	set_signal(SIGUSR2, &end_receipt);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	len = ft_strlen(message);
	if (!len)
		exit(EXIT_SUCCESS);
	send_len(server_pid, len);
	usleep(42);
	send_message(server_pid, message);
	return (EXIT_SUCCESS);
}
