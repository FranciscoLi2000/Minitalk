/* server.c - Server program for minitalk */
/* Author: your_login */
/* Description: Receives strings from clients using UNIX signals */

#define SERVER
#include "minitalk.h"

/* Global variables for signal handling */
char	*g_received_msg = NULL;
int		g_msg_index = 0;
int		g_msg_length = 0;
int		g_current_bit = 0;
int		g_current_bits[8];
int		g_end_signals = 0;

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	
	if (sig == USR1)
	{
		g_current_bits[g_current_bit] = 1;
		g_current_bit++;
		
		if (g_current_bit == 8)
		{
			char received_char = bit_to_char(g_current_bits);
			
			if (g_msg_index >= g_msg_length - 1)
			{
				g_msg_length += 1024;
				g_received_msg = realloc(g_received_msg, g_msg_length);
			}
			
			g_received_msg[g_msg_index] = received_char;
			g_msg_index++;
			g_received_msg[g_msg_index] = '\0';
			
			if (received_char == '\0')
			{
				g_end_signals++;
				if (g_end_signals >= 2)
				{
					ft_putstr("Server: Received message: ");
					ft_putstr(g_received_msg);
					ft_putstr("\n");
					
					g_msg_index = 0;
					g_current_bit = 0;
					g_end_signals = 0;
					
					if (g_received_msg)
						g_received_msg[0] = '\0';
				}
			}
			
			g_current_bit = 0;
		}
	}
	else if (sig == USR2)
	{
		g_current_bits[g_current_bit] = 0;
		g_current_bit++;
		
		if (g_current_bit == 8)
		{
			char received_char = bit_to_char(g_current_bits);
			
			if (g_msg_index >= g_msg_length - 1)
			{
				g_msg_length += 1024;
				g_received_msg = realloc(g_received_msg, g_msg_length);
			}
			
			g_received_msg[g_msg_index] = received_char;
			g_msg_index++;
			g_received_msg[g_msg_index] = '\0';
			
			if (received_char == '\0')
			{
				g_end_signals++;
				if (g_end_signals >= 2)
				{
					ft_putstr("Server: Received message: ");
					ft_putstr(g_received_msg);
					ft_putstr("\n");
					
					g_msg_index = 0;
					g_current_bit = 0;
					g_end_signals = 0;
					
					if (g_received_msg)
						g_received_msg[0] = '\0';
				}
			}
			
			g_current_bit = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;
	
	server_pid = getpid();
	
	ft_putstr("Server PID: ");
	ft_putnbr(server_pid);
	ft_putstr("\n");
	ft_putstr("Server is ready to receive messages...\n");
	
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	
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
	
	g_msg_length = 1024;
	g_received_msg = malloc(g_msg_length);
	if (!g_received_msg)
	{
		ft_putstr("Error: Failed to allocate memory\n");
		exit(1);
	}
	g_received_msg[0] = '\0';
	
	g_current_bit = 0;
	g_end_signals = 0;
	
	while (1)
	{
		pause();
	}
	
	if (g_received_msg)
	{
	free(g_received_msg);
	}
	
	return (0);
}