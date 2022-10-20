# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 10:15:27 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/18 15:32:52 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = printf output output2 utils

SRCS = $(addprefix ft_, $(addsuffix .c, $(FILES)))

OBJS = $(SRCS:.c=.o)

FILES_BONUS = printf atoi parsing parsing2 output output2 utils count

SRCS_BONUS = $(addprefix fb_, $(addsuffix _bonus.c, $(FILES_BONUS)))

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
