#include "minitalk.h"

void	send_binary_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)// se o bit atual é = 1
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1; // avançar para o próximo bit
		i++;
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
	int		pid;
	char	*msg;

	pid = ft_atoi(argv[1]);
	msg = argv[2];
	if (argc == 3 && verify_params(argv))
	{
		while (*msg)
			send_binary_char(pid, *msg++);
	}
}