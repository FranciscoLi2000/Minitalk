/* server_v2.c - Server program for minitalk - Version 2 */
/* Author: your_login */
/* Description: Receives strings from clients using UNIX signals */

#define SERVER
#include "minitalk.h"

/* Global variables for signal handling */
char	*g_received_msg = NULL;  /* Buffer for received message */
int		g_msg_index = 0;         /* Current index in buffer */
int		g_msg_length = 0;        /* Total length of message */
int		g_current_bit = 0;        /* Current bit position (0-7) */
int		g_current_bits[8];        /* Array to store current byte bits */
int		g_end_signals = 0;       /* Counter for end signals */
int		g_byte_complete = 0;      /* Flag for byte completion */

/**
 * handle_signal - Signal handler for SIGUSR1 and SIGUSR2
 * @sig: Signal number
 * @info: Signal information structure
 * @context: Signal context (unused)
 *
 * This function processes incoming signals:
 * - SIGUSR1: Represents bit 1
 * - SIGUSR2: Represents bit 0
 */
void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)info; /* Unused parameter */
	(void)context; /* Unused parameter */
	
	if (sig == USR1)
	{
		/* Handle bit 1 */
		g_current_bits[g_current_bit] = 1;
		g_current_bit++;
		
		/* Check if we completed a byte */
		if (g_current_bit == 8)
		{
			/* Convert bits to character */
			char received_char = bit_to_char(g_current_bits);
			
			/* Resize buffer if needed */
			if (g_msg_index >= g_msg_length - 1)
			{
				g_msg_length += 1024;
				g_received_msg = realloc(g_received_msg, g_msg_length);
			}
			
			g_received_msg[g_msg_index] = received_char;
			g_msg_index++;
			g_received_msg[g_msg_index] = '\0';
			
			/* Reset for next byte */
			g_current_bit = 0;
			g_byte_complete = 1;
		}
	}
	else if (sig == USR2)
	{
		/* Handle bit 0 */
		g_current_bits[g_current_bit] = 0;
		g_current_bit++;
		
		/* Check if we completed a byte */
		if (g_current_bit == 8)
		{
			/* Convert bits to character */
			char received_char = bit_to_char(g_current_bits);
			
			/* Resize buffer if needed */
			if (g_msg_index >= g_msg_length - 1)
			{
				g_msg_length += 1024;
				g_received_msg = realloc(g_received_msg, g_msg_length);
			}
			
			g_received_msg[g_msg_index] = received_char;
			g_msg_index++;
			g_received_msg[g_msg_index] = '\0';
			
			/* Reset for next byte */
			g_current_bit = 0;
			g_byte_complete = 1;
		}
	}
	
	/* Handle byte completion */
	if (g_byte_complete)
	{
		g_byte_complete = 0;
		
		/* Check if this was a null terminator */
		if (g_received_msg[g_msg_index - 1] == '\0')
		{
			/* End of message */
			g_end_signals++;
			
			if (g_end_signals >= 2)
			{
				/* Print the complete message */
				ft_putstr("Server: Received message: ");
				ft_putstr(g_received_msg);
				ft_putstr("\n");
				
				/* Reset for next message */
				g_msg_index = 0;
				g_current_bit = 0;
				g_end_signals = 0;
				
				/* Clear the buffer but keep allocated memory */
				if (g_received_msg)
					g_received_msg[0] = '\0';
			}
		}
	}
}

/**
 * main - Server entry point
 */
int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;
	
	/* Get server PID */
	server_pid = getpid();
	
	ft_putstr("Server PID: ");
	ft_putnbr(server_pid);
	ft_putstr("\n");
	ft_putstr("Server is ready to receive messages...\n");
	
	/* Initialize signal handler */
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	
	/* Register signal handlers */
	if (sigaction(USR1, &sa, NULL) == -1)
	{
		ft_putstr("Error: Failed to register SIGUSR1 handler\n");
		exit(1);
	}
	
	if (sigaction(USR2, &sa, NULL) == -1)
	{
		ft_putstr("Error: Failed to register SIGUSR2 handler\n");
		exit(1);
	}
	
	/* Allocate initial buffer */
	g_msg_length = 1024;
	g_received_msg = malloc(g_msg_length);
	if (!g_received_msg)
	{
		ft_putstr("Error: Failed to allocate memory\n");
		exit(1);
	}
	g_received_msg[0] = '\0';
	
	/* Initialize signal handling state */
	g_current_bit = 0;
	g_end_signals = 0;
	g_byte_complete = 0;
	
	/* Infinite loop to keep server running */
	while (1)
	{
		pause(); /* Wait for signals */
	}
	
	/* Clean up (should never reach here) */
	if (g_received_msg)
	{
	.free(g_received_msg);
	}
	
	return (0);
}