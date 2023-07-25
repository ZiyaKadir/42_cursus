CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = cc
AR = ar -rcs

SRC_DIR = src
INC_DIR = inc
SRCB_DIR = srcb
OBJ_DIR = obj
OBJB_DIR = objb

NAME = libftprintf.a
LIBFT = libft/libft.a



SRC  = ft_printf.c			\
		ft_printf_parse.c		\
		ft_printf_chars.c		\
		ft_printf_nbrs.c		\
		ft_printf_hex.c

SRCB = ft_printf_bonus.c			\
		ft_printf_parse_bonus.c		\
		ft_printf_chars_bonus.c		\
		ft_printf_nbrs_bonus.c		\
		ft_printf_hex_bonus.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJB = $(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))


all: $(NAME)

$(NAME): create_dirs compile_libft $(OBJ)
		$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs compile_libft $(OBJB)
	$(AR) $(NAME) $(OBJB)

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

compile_libft:
	@make all -C libft
	@cp $(LIBFT) $(NAME)

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJB_DIR)

clean:

	@make clean -C libft
	$(RM) -r $(OBJ_DIR)
	$(RM) -r $(OBJB_DIR)

fclean: clean
	@make fclean -C libft
	$(RM) -r $(NAME)

re: fclean all


.PHONY: all clean fclean bonus re compile_libft create_dirs