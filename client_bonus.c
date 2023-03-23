/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:19:48 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/03/23 15:18:07 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	signal_from_server(int sig, siginfo_t *info, void *context)
{
	(void) context;
	if (sig == SIGUSR2)
		write(1, "Mensagem enviada 🥳\n", 22);
}

void	send_binary_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		i++;
		usleep(100);
	}
}

int	verify_params(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int					pid;
	char				*msg;
	struct sigaction	sa;

	sa.sa_sigaction = &signal_from_server;
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	if (argc == 3 && verify_params(argv))
	{
		sigaction(SIGUSR2, &sa, NULL);
		while (*msg)
			send_binary_char(pid, *msg++);
		send_binary_char(pid, '\0');
	}
	return (0);
}
