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
