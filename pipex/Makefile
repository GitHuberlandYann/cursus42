# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 14:05:55 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/31 14:11:30 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FILES = main

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILES)))

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
