# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 10:15:27 by yhuberla          #+#    #+#              #
#    Updated: 2022/11/25 13:38:28 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS_DIR = OBJS

FILES = printf output output2 utils

SRCS = $(addprefix ft_, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

FILES_BONUS = printf atoi parsing parsing2 output output2 utils count

SRCS_BONUS = $(addprefix fb_, $(addsuffix _bonus.c, $(FILES_BONUS)))

OBJS_BONUS = $(addprefix $(OBJS_DIR)/, $(SRCS_BONUS:.c=.o))

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

# ==============------------------====================------------------=========

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS_DIR) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@mv $(<:.c=.o) $(OBJS_DIR)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
