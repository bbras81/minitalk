# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 14:03:38 by brunmigu          #+#    #+#              #
#    Updated: 2025/06/06 14:10:00 by brunmigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========================== #
#      CONFIGURAÇÃO          #
# ========================== #

NAME_CLIENT = client
#NAME_SERVER = server

SRCS_CLIENT = client.c libft/ft_atoi.c
#SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INCLUDE = -I.
RM      = rm -f

# ========================== #
#          REGRAS            #
# ========================== #

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)
	@echo "✅ $(NAME_CLIENT) compilado com sucesso!"

#$(NAME_SERVER): $(OBJS_SERVER)
#	@$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)
#	@echo "✅ $(NAME_SERVER) compilado com sucesso!"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔧 Compilado: $< → $@"

clean:
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	@echo "🧹 Objetos removidos!"

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "🔥 Executáveis removidos!"

re: fclean all
	@echo "♻️  Projeto recompilado do zero!"

.PHONY: all clean fclean re

