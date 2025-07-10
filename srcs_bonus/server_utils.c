#include "minitalk.h"

void	process_bit(int sig, siginfo_t *info)
{
	static unsigned char	c;
	static int			bit;
	static pid_t			client_pid;

	c = 0;
	bit = 0;
	client_pid = 0;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		bit = 0;
	}
	c |= (sig == SIGUSR1) << (7 - bit);
	bit++;
	if (bit == 8)
	{
		print_char_notify(c, client_pid);
		c = 0;
		bit = 0;
	}
	kill(client_pid, SIGUSR1);
}

void	print_char_notify(unsigned char c, pid_t client_pid)
{
	if (c == '\0')
	{
		write(1, "\n", 1);
		kill(client_pid, SIGUSR2);
	}
	else
		write(1, &c, 1);
}
