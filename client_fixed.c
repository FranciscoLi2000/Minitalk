/* client_fixed.c - Fixed version of client for minitalk with bidirectional communication */
#include "minitalk.h"

/* Global variable for acknowledgment flag */
static volatile sig_atomic_t	g_ack_received = 0;

/**
 * handle_ack - Signal handler for receiving acknowledgments from server
 * @sig: Signal number
 */
static void	handle_ack(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

/**
 * send_bit_with_ack - Send a single bit and wait for acknowledgment
 * @pid: Process ID of the server
 * @bit: Bit value (0 or 1)
 */
static void	send_bit_with_ack(pid_t pid, int bit)
{
	/* Reset acknowledgment flag */
	g_ack_received = 0;
	
	/* Send the bit */
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr("Error: Failed to send SIGUSR1\n");
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr("Error: Failed to send SIGUSR2\n");
			exit(1);
		}
	}
	
	/* Wait for acknowledgment using a more reliable method */
	int timeout = 0;
	while (!g_ack_received && timeout < 100)  /* Timeout after ~1 second */
	{
		usleep(10000);  /* Sleep for 10ms */
		timeout++;
	}
	
	if (!g_ack_received)
	{
		ft_putstr("Error: Timeout waiting for acknowledgment\n");
		exit(1);
	}
}

/**
 * send_byte - Send a single byte (8 bits, LSB first)
 * @pid: Process ID of the server
 * @byte: Byte to send
 */
static void	send_byte(pid_t pid, char byte)
{
	int	i;
	
	/* Send each bit, starting with LSB */
	for (i = 0; i < 8; i++)
	{
		int bit = (byte >> i) & 1;
		send_bit_with_ack(pid, bit);
	}
}

/**
 * send_string - Send a complete string
 * @pid: Process ID of the server
 * @str: String to send
 */
static void	send_string(pid_t pid, char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		send_byte(pid, str[i]);
		i++;
	}
	
	/* Send null terminator to indicate end of message */
	send_byte(pid, '\0');
}

/**
 * main - Client entry point
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Usage: ./client <server_pid> <message>
 */
int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*message;
	struct sigaction	sa;
	
	/* Check arguments */
	if (argc != 3)
	{
		ft_putstr("Usage: ./client <server_pid> <message>\n");
		return (1);
	}
	
	/* Parse server PID */
	server_pid = atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr("Error: Invalid server PID\n");
		return (1);
	}
	
	message = argv[2];
	
	ft_putstr("Client: Sending message to server ");
	ft_putnbr(server_pid);
	ft_putstr("... ");
	ft_putstr(message);
	ft_putstr("\n");
	
	/* Set up signal handler for acknowledgments */
	sa.sa_handler = handle_ack;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr("Error: Failed to register acknowledgment handler\n");
		return (1);
	}
	
	/* Send the string */
	send_string(server_pid, message);
	
	ft_putstr("Client: Message sent successfully!\n");
	
	return (0);
}