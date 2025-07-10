# ========= CONFIG ============
NAME_SERVER    = server
NAME_CLIENT    = client

CC             = cc
CFLAGS         = -Wall -Wextra -Werror
INCDIRS        = -Iincludes -Ilibft

SRCDIR         = srcs
BONUSDIR       = srcs_bonus
OBJDIR         = objs

LIBFTDIR       = libft
LIBFT          = $(LIBFTDIR)/libft.a

SRC_SERVER     = $(wildcard $(SRCDIR)/server*.c)
SRC_CLIENT     = $(wildcard $(BONUSDIR)/client*.c)

OBJ_SERVER     = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC_SERVER))
OBJ_CLIENT     = $(patsubst $(BONUSDIR)/%.c, $(OBJDIR)/%.o, $(SRC_CLIENT))

# ========= RULES =============

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(INCDIRS) $(OBJ_SERVER) $(LIBFT) -o $@

$(NAME_CLIENT): $(LIBFT) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(INCDIRS) $(OBJ_CLIENT) $(LIBFT) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

$(OBJDIR)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

# ========= CLEANING ==========
clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

# ========= BONUS 支持（可选）=======
bonus:
	$(MAKE) NAME_SERVER=server_bonus NAME_CLIENT=client_bonus \
		SRCDIR=srcs_bonus all

# ========= DEBUG 编译（调试用） ======
debug:
	$(MAKE) CFLAGS="-g3 -fsanitize=address -Wall -Wextra -Werror" re

# ========= PHONY RULES =========
.PHONY: all clean fclean re bonus debug
