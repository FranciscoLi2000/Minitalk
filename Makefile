# **************************************************************************** #
#                              MINITALK Makefile                               #
# **************************************************************************** #

NAME_SERVER	= server
NAME_CLIENT	= client

# -----------------------------------------------------------------------------

SRCS_DIR	= srcs/
LIBFT_DIR	= libft/
INC_DIR		= includes/

SRCS_SERVER	= $(SRCS_DIR)server.c $(SRCS_DIR)server_utils.c
SRCS_CLIENT	= $(SRCS_DIR)client.c $(SRCS_DIR)client_utils.c

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)

CC			= cc
CFLAGS			= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)

# -----------------------------------------------------------------------------

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@

$(NAME_CLIENT): $(OBJS_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@

# -----------------------------------------------------------------------------

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
