#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s PID message\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID %s\n", argv[1]);
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, ack_handler);
	send_str(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
