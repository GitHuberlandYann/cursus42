# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 14:05:55 by yhuberla          #+#    #+#              #
#    Updated: 2023/01/08 15:34:38 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
OBJS_DIR = Objs
OBJS_DIR_SRCS = Objs/SRCS
OBJS_DIR_BONUS = Objs/BONUS

FILES = main execve path utils

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

SRCS_BONUS = $(addprefix BONUS/, $(addsuffix .c, $(FILES)))

SRCS_BONUS += BONUS/here_doc.c

OBJS_BONUS = $(addprefix $(OBJS_DIR)/, $(SRCS_BONUS:.c=.o))

# ===---===---===---===---===---===---===---===---===---===---===---===---

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# ===---===---===---===---===---===---===---===---===---===---===---===---

LIBFT_DIR = Libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a
LIBFT_OBJS = $(LIBFT_DIR)/Objs

LIBFT = $(LIBFT_PATH)

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: $(OBJS_DIR_SRCS) $(NAME)

$(OBJS_DIR_SRCS):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/SRCS

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(OBJS_DIR)/SRCS/%.o: SRCS/%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@mv $(<:.c=.o) $(OBJS_DIR)/SRCS

bonus: $(OBJS_DIR_BONUS) $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME) $(LIBFT)

$(OBJS_DIR_BONUS):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/BONUS

$(OBJS_DIR)/BONUS/%.o: BONUS/%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@mv $(<:.c=.o) $(OBJS_DIR)/BONUS

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re NAME OBJS_DIR LIBFT
