# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 15:20:27 by kkaman            #+#    #+#              #
#    Updated: 2025/11/15 23:08:45 by kkaman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC	= cc

CFLAG	= -Wall -Wextra -Werror -fPIC

AR	= ar rcs

RM	= rm -f

SRC	= ft_printf.c parse_format.c parse_utils.c print_char.c print_string.c \
	  print_int.c print_int_utils.c print_unsigned.c print_unsigned_utils.c \
	  print_hex.c print_hex_utils.c print_pointer.c print_pointer_utils.c \
	  print_percent.c ft_strlen.c ft_memset.c number_utils.c print_utils.c

OBJ	= $(SRC:.c=.o)

ALL	= $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
