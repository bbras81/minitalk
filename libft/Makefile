# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 14:41:38 by brunmigu          #+#    #+#              #
#    Updated: 2025/07/17 10:50:51 by brunmigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_libft/ft_isalpha.c \
	ft_libft/ft_isdigit.c \
	ft_libft/ft_isascii.c \
	ft_libft/ft_isalnum.c \
	ft_libft/ft_isprint.c \
	ft_libft/ft_tolower.c \
	ft_libft/ft_toupper.c \
	ft_libft/ft_bzero.c \
	ft_libft/ft_memset.c \
	ft_libft/ft_memcpy.c \
	ft_libft/ft_memmove.c \
	ft_libft/ft_strchr.c \
	ft_libft/ft_strlen.c \
	ft_libft/ft_strlcpy.c \
	ft_libft/ft_strlcat.c \
	ft_libft/ft_strrchr.c \
	ft_libft/ft_strncmp.c \
	ft_libft/ft_memchr.c \
	ft_libft/ft_memcmp.c \
	ft_libft/ft_strnstr.c \
	ft_libft/ft_atoi.c \
	ft_libft/ft_atol.c \
	ft_libft/ft_calloc.c \
	ft_libft/ft_strdup.c \
	ft_libft/ft_substr.c \
	ft_libft/ft_strjoin.c \
	ft_libft/ft_strtrim.c \
	ft_libft/ft_split.c \
	ft_libft/ft_itoa.c \
	ft_libft/ft_strmapi.c \
	ft_libft/ft_striteri.c \
	ft_libft/ft_putchar_fd.c \
	ft_libft/ft_putstr_fd.c \
	ft_libft/ft_putendl_fd.c \
	ft_libft/ft_putnbr_fd.c \
	ft_libft/ft_lstadd_back.c \
	ft_libft/ft_lstadd_front.c \
	ft_libft/ft_lstclear.c \
	ft_libft/ft_lstdelone.c \
	ft_libft/ft_lstiter.c \
	ft_libft/ft_lstlast.c \
	ft_libft/ft_lstnew.c \
	ft_libft/ft_lstsize.c\
	ft_get_next_line/get_next_line.c \
	ft_get_next_line/get_next_line_utils.c \
	ft_get_next_line/get_next_line_bonus.c \
	ft_get_next_line/get_next_line_utils_bonus.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_print_char.c \
	ft_printf/ft_print_str.c \
	ft_printf/ft_print_dec.c \
	ft_printf/ft_print_udec.c \
	ft_printf/ft_print_hex.c \
	ft_printf/ft_print_ptr.c

OBJS = $(SRCS:.c=.o)

RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
COMPILER = cc
INCLUDE = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "libft.a compiled successfully."


%.o: %.c
	@$(COMPILER) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
	@echo "Object files cleaned successfully."

fclean: clean
	@$(RM) $(NAME) $(GNL_NAME) $(PRINTF_NAME)
	@echo "All libraries cleaned successfully."

re: fclean all

.PHONY: all clean fclean re get_next_line ft_printf
