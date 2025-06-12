# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 14:03:38 by brunmigu          #+#    #+#              #
#    Updated: 2025/06/10 06:09:09 by brunmigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

SRCS_CLIENT_BONUS = client_bonus.c
SRCS_SERVER_BONUS = server_bonus.c

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INCLUDE = -Ilibft
RM      = rm -f

# Se usares a libft, descomenta as linhas seguintes
LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(NAME_CLIENT) $(NAME_SERVER)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT_A) -o $(NAME_CLIENT)
	@echo "✅ $(NAME_CLIENT) compilado com sucesso!"

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT_A) -o $(NAME_SERVER)
	@echo "✅ $(NAME_SERVER) compilado com sucesso!"

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(LIBFT_A) -o $(NAME_CLIENT_BONUS)
	@echo "✅ $(NAME_SERVER) compilado com sucesso!"

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(LIBFT_A) -o $(NAME_SERVER_BONUS)
	@echo "✅ $(NAME_SERVER) compilado com sucesso!"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔧 Compilado: $< → $@"

clean:
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Objetos removidos!"

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🔥 Executáveis removidos!"

re: fclean all
	@echo "♻️  Projeto recompilado do zero!"

.PHONY: all clean fclean re

