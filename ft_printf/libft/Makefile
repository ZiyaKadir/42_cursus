# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztokluog <ztokluog@student.42kocaeli.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 16:38:14 by ztokluog          #+#    #+#              #
#    Updated: 2023/:4307/16 23:36 by ztokluog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
LIBC	:= ar -rcs
RM		:= rm -f

SRCS			:=	ft_atoi.c ft_bzero.c ft_calloc.c ft_count_digit_base.c \
					ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
					ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c \
					ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
					ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_putnchar_fd.c ft_putstr_fd.c ft_putstrn_fd.c ft_split.c \
					ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
					ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
					ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
					ft_uitoa.c


OBJS	:= $(SRCS:%.c=%.o)
INCS	:= libft.h

BSRCS			:=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c
B_OBJS	:= $(BSRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(OBJS) $(B_OBJS)
		$(LIBC) $(NAME) $(OBJS) $(B_OBJS)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re