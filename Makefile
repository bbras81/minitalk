# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 10:17:38 by brunmigu          #+#    #+#              #
#    Updated: 2025/06/27 10:37:30 by brunmigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MANDATORY = client.c server.c utils.c
SRCS_BONUS = client_bonus.c server_bonus.c utils_bonus.c

OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC      = cc
CFLAGS  = -g #-Wall -Wextra -Werror
INCLUDE = -Ilibft
RM      = rm -f

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: server client server_bonus client_bonus

mandatory: server client

server: server.o utils.o $(LIBFT_A)
	@$(CC) $(CFLAGS) server.o utils.o $(LIBFT_A) -o server
	@echo "✅ server compilado com sucesso!"

client: client.o utils.o $(LIBFT_A)
	@$(CC) $(CFLAGS) client.o utils.o $(LIBFT_A) -o client
	@echo "✅ client compilado com sucesso!"

server_bonus: server_bonus.o utils_bonus.o $(LIBFT_A)
	@$(CC) $(CFLAGS) server_bonus.o utils_bonus.o $(LIBFT_A) -o server_bonus
	@echo "✅ server_bonus compilado com sucesso!"

client_bonus: client_bonus.o utils_bonus.o $(LIBFT_A)
	@$(CC) $(CFLAGS) client_bonus.o utils_bonus.o $(LIBFT_A) -o client_bonus
	@echo "✅ client_bonus compilado com sucesso!"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔧 Compilado: $< → $@"

clean:
	@$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Objetos removidos!"

fclean: clean
	@$(RM) server client server_bonus client_bonus
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🔥 Executáveis removidos!"

re: fclean all
	@echo "♻️  Projeto recompilado do zero!"

.PHONY: all clean fclean re
