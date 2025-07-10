#include "minitalk.h"

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	process_bit(signo, info);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID = %d\n", getpid());

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
