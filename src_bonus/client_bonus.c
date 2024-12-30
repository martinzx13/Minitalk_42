/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:28:28 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/27 16:33:26 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

void	ft_send_msg(int pid, char *msg)
{
	int				bytes_iter;
	unsigned char	message_words;

	while (*msg)
	{
		message_words = *msg;
		bytes_iter = 8;
		while (bytes_iter--)
		{
			if (message_words & (1 << bytes_iter))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		msg++;
	}
}

void	sign_handler(int pid)
{
	if (pid == SIGUSR2)
		ft_putstr("Signal Received \n");
}

void	ft_signals_init(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &sign_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1) 
		ft_putstr("Error SIGUSER1 \n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr("Error SIGUSER2 \n");
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		if (!ft_checker(argv[1]))
		{
			ft_putstr("Error with the PID, only alphabetic characters");
			return (EXIT_FAILURE);
		}
		pid = atoi(argv[1]);
		ft_signals_init();
		ft_send_msg(pid, argv[2]);
	}
	else
	{
		ft_putstr("Usage: ./server <server_pid> <message>\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
