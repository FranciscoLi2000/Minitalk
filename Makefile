# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 15:19:46 by yufli             #+#    #+#              #
#    Updated: 2025/05/18 23:48:01 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilador i flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Iincludes

# Carpetes
SRC_DIR     = sources
BONUS_DIR   = sources_bonus
LIBFT_DIR   = libft

# Executables
CLIENT      = client
SERVER      = server
CLIENT_B    = client_bonus
SERVER_B    = server_bonus

# Fitxers font
SRC_FILES       = $(SRC_DIR)/client.c $(SRC_DIR)/server.c
BONUS_FILES     = $(BONUS_DIR)/client_bonus.c $(BONUS_DIR)/server_bonus.c
LIBFT_FILES     = $(wildcard $(LIBFT_DIR)/*.c)

# Objectes
OBJS_CLIENT     = $(SRC_DIR)/client.o $(LIBFT_FILES:.c=.o)
OBJS_SERVER     = $(SRC_DIR)/server.o $(LIBFT_FILES:.c=.o)
OBJS_CLIENT_B   = $(BONUS_DIR)/client_bonus.o $(LIBFT_FILES:.c=.o)
OBJS_SERVER_B   = $(BONUS_DIR)/server_bonus.o $(LIBFT_FILES:.c=.o)

# Regles
all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER)

bonus: $(CLIENT_B) $(SERVER_B)

$(CLIENT_B): $(OBJS_CLIENT_B)
	$(CC) $(CFLAGS) -o $(CLIENT_B) $(OBJS_CLIENT_B)

$(SERVER_B): $(OBJS_SERVER_B)
	$(CC) $(CFLAGS) -o $(SERVER_B) $(OBJS_SERVER_B)

clean:
	@echo "Netegem objectes..."
	rm -f $(SRC_DIR)/*.o $(BONUS_DIR)/*.o $(LIBFT_DIR)/*.o

fclean: clean
	@echo "Esborrem executables..."
	rm -f $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)

re: fclean all

.PHONY: all clean fclean re bonus
