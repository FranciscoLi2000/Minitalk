#include "minitalk.h"
#include "libft.h"

static void	send_bit(pid_t pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	send_char(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		send_bit(pid, (c >> bit) & 1);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
