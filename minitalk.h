/* minitalk.h - Header file for minitalk project */
/* Author: your_login */
/* Description: Contains function prototypes, constants, and structures for minitalk */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>

/* Constants */
# define USR1 SIGUSR1
# define USR2 SIGUSR2

/* Function prototypes */

/* Utility functions */
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);

/* Client functions for sending data */

#endif