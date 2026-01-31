#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	handle_signal(int sig);
void	send_char(pid_t pid, unsigned char c);

#endif
