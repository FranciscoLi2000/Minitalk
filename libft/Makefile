# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 09:52:32 by yufli             #+#    #+#              #
#    Updated: 2025/06/07 00:55:36 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# LIBRARY CONFIGURATION
# =============================================================================
# The name of your unified library - this becomes your personal toolkit
NAME = libft.a

# Compiler configuration - standard 42 School requirements plus optimization
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
AR = ar rcs
RM = rm -rf

# =============================================================================
# SOURCE FILE ORGANIZATION
# =============================================================================
# All your libft foundation functions - the core of your toolkit
LIBFT_SRCS = ft_strlen.c ft_itoa.c ft_strchr.c ft_strdup.c ft_substr.c \
             ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
             ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
             ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
             ft_memcmp.c ft_calloc.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
             ft_strnstr.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
             ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strrchr.c \
             ft_atoi_base.c ft_strcmp.c ft_strcpy.c ft_strcat.c ft_strncat.c \
             ft_strncpy.c ft_strstr.c ft_strpbrk.c ft_strcspn.c ft_strspn.c \
             ft_strrev.c ft_range.c ft_rrange.c ft_swap.c ft_is_prime.c \
             ft_isspace.c is_power_of_2.c lcm.c max.c print_bits.c \
             reverse_bits.c sort_int_tab.c swap_bits.c

# Your enhanced printf implementation - advanced formatting capabilities
PRINTF_SRCS = ft_printf.c ft_formats.c ft_utils.c

# File reading functionality - essential for many programs
GNL_SRCS = get_next_line.c

# Combine all source files - this represents your complete toolkit
ALL_SRCS = $(LIBFT_SRCS) $(PRINTF_SRCS) $(GNL_SRCS)

# Generate object file names from source files
ALL_OBJS = $(ALL_SRCS:.c=.o)

# =============================================================================
# COLOR CONFIGURATION FOR BEAUTIFUL OUTPUT
# =============================================================================
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

# =============================================================================
# BUILD TARGETS
# =============================================================================

# Default target - builds your complete unified library
all: $(NAME)

# Creates the unified library containing all your functions
# This is the heart of your reusable toolkit
$(NAME): $(ALL_OBJS)
	@echo "$(CYAN)================================================$(RESET)"
	@echo "$(MAGENTA)    Building Personal Toolkit: $(NAME)$(RESET)"
	@echo "$(CYAN)================================================$(RESET)"
	@echo "$(BLUE)Archiving $(words $(ALL_OBJS)) object files...$(RESET)"
	@$(AR) $(NAME) $(ALL_OBJS)
	@echo ""
	@echo "$(GREEN)✓ SUCCESS! Your personal library is ready!$(RESET)"
	@echo "$(YELLOW)Library Contents:$(RESET)"
	@echo "Core libft functions: $(words $(LIBFT_SRCS))"
	@echo "Enhanced printf: $(words $(PRINTF_SRCS))"
	@echo "File reading (GNL): $(words $(GNL_SRCS))"
	@echo "Total functions: $(words $(ALL_OBJS))"
	@echo ""
	@echo "$(CYAN)Usage in other projects:$(RESET)"
	@echo "Compile: cc -Wall -Wextra -Werror "
	@echo " -I/home/yufli/Documents/libft program.c "
	@echo " -L/home/yufli/Documents/libft -lft "
	@echo "$(CYAN)================================================$(RESET)"

# Pattern rule for compiling individual source files
# This rule applies to all .c files regardless of their function category
%.o: %.c
	@echo "$(BLUE)Compiling $< → $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# =============================================================================
# MAINTENANCE TARGETS
# =============================================================================

# Remove object files but preserve the library
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(ALL_OBJS)
	@echo "$(GREEN)✓ Removed $(words $(ALL_OBJS)) object files$(RESET)"

# Complete cleanup - removes everything
fclean: clean
	@echo "$(RED)Removing library $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ Complete cleanup finished$(RESET)"

# Rebuild everything from scratch
re: fclean all

# =============================================================================
# PHONY TARGETS
# =============================================================================
# These targets don't create files, so we mark them as phony to avoid conflicts
.PHONY: all clean fclean re
