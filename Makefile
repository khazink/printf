# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 15:20:27 by kkaman            #+#    #+#              #
#    Updated: 2025/10/29 15:20:29 by kkaman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= printf.a

CC	= cc

CFLAG	= -Wall -Wextra -Werror

AR	= ar rcs

RM	= rm -f

SRC	= ft_printf.c ft_putchar.c

OBJ	= $(SRC:.c=.o)

ALL	= $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
