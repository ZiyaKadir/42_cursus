CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f
SRC_SERVER	= server.c
SRC_CLIENT = client.c
NAME_SERVER = server
NAME_CLIENT = client
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

%.o:%.c
		$(CC) $(CFLAGS) -c $< -o $@ 

all: libft $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
		$(CC)  $(OBJ_SERVER) -o $(NAME_SERVER) -L./libft -lft

$(NAME_CLIENT): $(OBJ_CLIENT)
		$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT) -L./libft -lft

bonus: all 

libft: 
	@make -C libft

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) 
	@make -C libft clean

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) ./libft/libft.a

re:	fclean all

.PHONY: all fclean clean re libft 
