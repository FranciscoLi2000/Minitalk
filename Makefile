# Makefile for minitalk project
# Author: your_login

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_SERVER = server
NAME_CLIENT = client

# Source files
SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c

# Object files
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Header files
HEADERS = minitalk.h

# Default target
all: $(NAME_SERVER) $(NAME_CLIENT)

# Compile server
$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

# Compile client
$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

# Create object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

# Clean all generated files
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

# Recompile everything
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re