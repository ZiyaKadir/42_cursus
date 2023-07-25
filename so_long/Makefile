# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 04:34:12 by Ziya Kadir TOKLU  #+#    #+#              #
#    Updated: 2023/07/19 16:18:03 by Ziya Kadir TOKLU ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc -lm
FLAGS = -Werror -Wextra -Wall
RM = rm -rf

MAIN = main.o

SOURCE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./src/create_map.c ./src/so_long_utils.c ./src/get_counts.c \
		./src/check_rectangular.c ./src/split_map.c ./src/check_valid.c ./src/init_data.c ./img_src/put_xpm.c ./img_src/key_events.c ./img_src/key_checkers.c

SOURCE_BONUS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./src_bonus/create_map.c ./src_bonus/so_long_utils.c ./src_bonus/get_counts.c \
		./src_bonus/check_rectangular.c ./src_bonus/split_map.c ./src_bonus/check_valid.c ./src_bonus/init_data.c ./img_src_bonus/put_xpm.c ./img_src_bonus/key_events.c ./img_src_bonus/key_checkers.c \
		./img_src_bonus/animation_all.c ./img_src_bonus/animation_collect.c ./img_src_bonus/animation_villian.c ./img_src_bonus/init_xpm.c ./img_src_bonus/print_moves.c ./img_src_bonus/animation_dir.c

OBJECT= $(SOURCE:%.c.=%.o)
OBJECT_BONUS = $(SOURCE_BONUS:%.c.=%.o)

all: $(NAME) $(NAME_BONUS) 

$(NAME): $(MAIN) $(OBJECT)
	@make -C ./ft_printf
	@make -C ./mlx
	$(CC) $(FLAGS) $(OBJECT) -framework OpenGL -framework AppKit mlx/libmlx.a ./ft_printf/libftprintf.a $(MAIN) -o $(NAME)

$(NAME_BONUS): $(MAIN) $(OBJECT_BONUS)
	@make -C ./ft_printf
	@make -C ./mlx
	$(CC) $(FLAGS) $(OBJECT_BONUS) -framework OpenGL -framework AppKit mlx/libmlx.a ./ft_printf/libftprintf.a $(MAIN) -o $(NAME_BONUS)

clean:
	$(RM) src_bonus/*.o ft_printf/*.o get_next_line/*.o $(MAIN) img_src_bonus/*.o img_src/*.o src/*.o
	@make -C ./ft_printf fclean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	@make -C ./mlx clean

re: fclean all

.PHONY: all clean fclean re