# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 13:05:50 by jhvalenc          #+#    #+#              #
#    Updated: 2025/02/17 13:37:32 by jhvalenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

SOURCE = ft_strlen.c \
	 ft_itoa.c \
	 ft_itoa_hex.c \
	 ft_itoa_ptr.c \
	 ft_itoa_unsigned.c \
	 ft_print_char.c \
	 ft_print_decimal_int.c \
	 ft_printf.c \
	 ft_print_hex_lower.c \
	 ft_print_hex_upper.c \
	 ft_print_int.c \
	 ft_print_pointer.c \
	 ft_print_string.c \
	 ft_print_unsigned_int.c

OBJ = $(SOURCE:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
