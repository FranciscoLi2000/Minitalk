#include "minitalk.h"
#include "libft.h"

static void	print_char(unsigned char c)
{
	if (c == '\0')
		write(1, "\n", 1);
	else
		write(1, &c, 1);
}

void	handle_signal(int sig)
{
	static unsigned char	c;
	static int				bit;

	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		print_char(c);
		c = 0;
		bit = 0;
	}
}

static void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	setup_signals();
	while (1)
		pause();
	return (0);
}
