/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:19:33 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/03/21 19:19:32 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *siginfo, void *context)
{
	static int	current_bit = 0;
	int			client_pid;
	static char	ascii = 0;

	(void) context;
	client_pid = siginfo->si_pid;
	if (sig == SIGUSR2)
		ascii += 1 << current_bit;
	if (current_bit == 7)
	{
		if (ascii == '\0')
			kill(client_pid, SIGUSR2);
		write(1, &ascii, 1);
		ascii = 0;
		current_bit = 0;
	}
	else
		current_bit++;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "PID : ", 6);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
