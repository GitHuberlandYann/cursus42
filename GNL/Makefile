# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 08:48:24 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/14 18:28:17 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = make.out

SRCS = get_next_line_utils.c get_next_line.c main.c

SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c

CFLAGS = -Wall -Wextra -Werror

BUFFER = -D BUFFER_SIZE=42

SANITIZE = -fsanitize=address -g

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(BUFFER) $(SRCS) -o $(NAME)

sanitize:
	gcc $(CFLAGS) $(SANITIZE) $(BUFFER) $(SRCS) -o $(NAME)

s: sanitize

bonus:
	gcc $(CFLAGS) $(SANITIZE) $(BUFFER) $(SRCS_BONUS) -o $(NAME)

.PHONY: all sanitize s