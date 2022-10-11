# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 08:48:24 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/11 09:09:54 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = make.out

SRCS = get_next_line_utils.c get_next_line.c main.c

CFLAGS = -Wall -Wextra -Werror

BUFFER = -D BUFFER_SIZE=42

SANITIZE = -fsanitize=address -g

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(BUFFER) $(SRCS) -o $(NAME)

sanitize:
	gcc $(CFLAGS) $(SANITIZE) $(BUFFER) $(SRCS) -o $(NAME)

s: sanitize

.PHONY: all sanitize s