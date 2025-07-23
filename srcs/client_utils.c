#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	ack_handler(int signo)
{
	if (signo == SIGUSR1)
		g_ack = 1;
	else if (signo == SIGUSR2)
	{
		ft_printf("Server received all\n");
		exit(0);
	}
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack)
			pause();
		i--;
	}
}

void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}
