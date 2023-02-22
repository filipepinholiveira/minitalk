#include "minitalk.h"

int main(void)
{
	int pid;

	pid =  getpid();
	write(1, "PID : ", 6);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		
	}
}