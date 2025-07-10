#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libft/libft.h"

void	sig_handler(int signo, siginfo_t *info, void *context);
int		main(void);
void	process_bit(int sig, siginfo_t *info);
void	print_char_notify(unsigned char c, pid_t client_pid);
void	ack_handler(int signo);
void	send_char(pid_t pid, char c);
void	send_str(pid_t pid, char *str);
int	main(int argc, char **argv);

#endif
