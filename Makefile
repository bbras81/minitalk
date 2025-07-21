# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 19:02:19 by brunmigu          #+#    #+#              #
#    Updated: 2025/07/21 12:32:15 by brunmigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MANDATORY = src/client.c src/server.c
SRCS_BONUS = src/client_bonus.c src/server_bonus.c

OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC      = cc
CFLAGS  = -g -Wall -Wextra -Werror
INCLUDE = -Ilibft
RM      = rm -f

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: server client server_bonus client_bonus

mandatory: server client

server: $(OBJS_MANDATORY) $(LIBFT_A)
	@$(CC) $(CFLAGS) src/server.o $(LIBFT_A) -o server
	@echo "✅ server compiled successfully!"

client: $(OBJS_MANDATORY) $(LIBFT_A)
	@$(CC) $(CFLAGS) src/client.o $(LIBFT_A) -o client
	@echo "✅ client compiled successfully!"

server_bonus: src/server_bonus.o $(LIBFT_A)
	@$(CC) $(CFLAGS) src/server_bonus.o $(LIBFT_A) -o server_bonus
	@echo "✅ server_bonus compiled successfully!"

client_bonus: src/client_bonus.o $(LIBFT_A)
	@$(CC) $(CFLAGS) src/client_bonus.o $(LIBFT_A) -o client_bonus
	@echo "✅ client_bonus compiled successfully!"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔧 Compiled: $< → $@"

clean:
	@$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Object files removed!"

fclean: clean
	@$(RM) server client server_bonus client_bonus
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🔥 Executables removed!"

re: fclean all
	@echo "♻️  Project fully rebuilt!"

.PHONY: all clean fclean re
