/* server_debug.c - Debug version of server for minitalk with bidirectional communication */
#include "minitalk.h"

/* Global variables for signal handling */
static int		g_bit_pos = 0;
static char		g_current_char = 0;
static char		g_message[65536];
static int		g_msg_index = 0;
static pid_t		g_client_pid = 0;

/**
 * send_ack - Send acknowledgment signal to client
 * @client_pid: PID of the client to acknowledge
 */
static void	send_ack(pid_t client_pid)
{
	ft_putstr("[DEBUG] Sending ACK to client PID: ");
	ft_putnbr(client_pid);
	ft_putstr("\n");
	
	if (client_pid > 0)
	{
		if (kill(client_pid, SIGUSR1) == -1)
		{
			ft_putstr("Error: Failed to send acknowledgment to client\n");
		}
	}
}

/**
 * handle_signal - Signal handler for receiving bits from client
 * @sig: Signal number
 * @info: Signal information structure
 * @context: Signal context (unused)
 */
static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	
	ft_putstr("[DEBUG] Received signal: ");
	ft_putstr(sig == SIGUSR1 ? "SIGUSR1" : "SIGUSR2");
	ft_putstr("\n");
	
	/* Store client PID for acknowledgment */
	if (info && info->si_pid > 0)
	{
		g_client_pid = info->si_pid;
		ft_putstr("[DEBUG] Client PID set to: ");
		ft_putnbr(g_client_pid);
		ft_putstr("\n");
	}
	
	/* Process the received bit */
	if (sig == SIGUSR1)
	{
		g_current_char |= (1 << g_bit_pos);
		ft_putstr("[DEBUG] Set bit ");
		ft_putnbr(g_bit_pos);
		ft_putstr(" to 1\n");
	}
	else if (sig == SIGUSR2)
	{
		g_current_char &= ~(1 << g_bit_pos);
		ft_putstr("[DEBUG] Set bit ");
		ft_putnbr(g_bit_pos);
		ft_putstr(" to 0\n");
	}
	
	g_bit_pos++;
	ft_putstr("[DEBUG] Bit position: ");
	ft_putnbr(g_bit_pos);
	ft_putstr("\n");
	
	/* When we have received 8 bits, process the complete byte */
	if (g_bit_pos == 8)
	{
		ft_putstr("[DEBUG] Complete byte received: '");
		ft_putchar(g_current_char);
		ft_putstr("' (");
		ft_putnbr((int)g_current_char);
		ft_putstr(")\n");
		
		/* Store the character in the message buffer */
		g_message[g_msg_index] = g_current_char;
		g_msg_index++;
		g_message[g_msg_index] = '\0';  /* Keep null-terminated */
		
		ft_putstr("[DEBUG] Message so far: '");
		ft_putstr(g_message);
		ft_putstr("'\n");
		
		/* Check if this is the null terminator (end of message) */
		if (g_current_char == '\0')
		{
			ft_putstr("Server: Received message: ");
			ft_putstr(g_message);
			ft_putstr("\n");
			
			/* Reset for next message */
			g_msg_index = 0;
			g_bit_pos = 0;
			g_current_char = 0;
			g_message[0] = '\0';
		}
		else
		{
			/* Reset for next byte */
			g_bit_pos = 0;
			g_current_char = 0;
		}
		
		/* Send acknowledgment to client */
		send_ack(g_client_pid);
	}
}

/**
 * main - Server entry point
 */
int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;
	
	server_pid = getpid();
	
	ft_putstr("Server PID: ");
	ft_putnbr(server_pid);
	ft_putstr("\n");
	ft_putstr("Server is ready to receive messages with acknowledgments...\n");
	
	/* Initialize message buffer */
	g_message[0] = '\0';
	
	/* Set up signal handler with sigaction */
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;  /* Get additional signal info */
	sigemptyset(&sa.sa_mask);
	
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr("Error: Failed to register SIGUSR1 handler\n");
		exit(1);
	}
	
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr("Error: Failed to register SIGUSR2 handler\n");
		exit(1);
	}
	
	ft_putstr("[DEBUG] Signal handlers registered successfully\n");
	
	/* Main server loop - wait for signals */
	while (1)
	{
		pause();
	}
	
	return (0);
}