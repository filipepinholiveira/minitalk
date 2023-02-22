#include "minitalk.h"


void	handle_signal(int sig, siginfo_t *siginfo, void *context)
{
	int buffer;
	int bit_count;

	buffer = 0;
	bit_count = 0;
	
	if (sig == SIGUSR1)
	{
		buffer <<= 1;
		bit_count++;
	}
	else if (sig == SIGUSR2)
	{
		buffer = (buffer << 1) | 1;
		bit_count++;
	}
	if (bit_count == 8)
	{
		ft_putchar_fd((char)buffer, 1);
		buffer = 0;
		bit_count = 0;
	}
}


int main(void)
{
	int pid;
	struct sigaction sa;
	
	pid =  getpid();
	write(1, "PID : ", 6);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;

		while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}