# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:43:12 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/08 20:40:42 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf ft_putchar_fd ft_putnbr_fd ft_putstr_fd ft_utils ft_utils2 \
		ft_utils3 ft_bonus ft_bonus_utils ft_bonus_utils2 ft_strlen main

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re