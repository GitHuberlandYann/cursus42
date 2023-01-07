# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 14:23:30 by yhuberla          #+#    #+#              #
#    Updated: 2023/01/07 17:41:25 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
OBJS_DIR = Objs
OBJS_DIR_SRCS = Objs/SRCS

FILES = builtins colors lexer main signal test utils

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# ===---===---===---===---===---===---===---===---===---===---===---===---

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
READLINE = -lreadline

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
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(READLINE) $(LIBFT)

$(OBJS_DIR)/SRCS/%.o: SRCS/%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(READLINE)
	@mv $(<:.c=.o) $(OBJS_DIR)/SRCS

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re NAME OBJS_DIR_SRCS LIBFT
