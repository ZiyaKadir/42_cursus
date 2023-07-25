CC	= cc
FLAGS	= -c -Wall -Wextra -Werror
LIB	= ar -rcs
NAME	= libft.a
RM	= rm -f
SRC	= sources/ft_itoa.c sources/ft_atoi.c sources/ft_printf.c sources/ft_putchar_fd.c sources/ft_putstr_fd.c sources/ft_strlen.c sources/ft_uitoa.c \

OBJ	= $(SRC:.c=.o) 

%.o:%.c
	$(CC) $(FLAGS) $< -o $@ 

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all fclean clean re 
