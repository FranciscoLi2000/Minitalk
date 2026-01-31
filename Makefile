NAME_SERVER 	= server
NAME_CLIENT 	= client

CC 		= cc
CFLAGS 		= -Wall -Wextra -Werror

INCLUDES 	= -Iincludes -Ilibft

LIBFT_DIR 	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a

SRCS_SERVER 	= srcs/server.c
SRCS_CLIENT 	= srcs/client.c

OBJS_SERVER 	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT 	= $(SRCS_CLIENT:.c=.o)

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
