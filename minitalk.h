# ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

//utils
int		ft_atoi(const char *str);
int		ft_isdigit(int arg);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

//client
void	send_binary_char(int pid, char c);
int	verify_params(char **argv);

//server
void	handle_signal(int sig, siginfo_t *siginfo, void *context);

#endif