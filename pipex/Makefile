# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 14:05:55 by yhuberla          #+#    #+#              #
#    Updated: 2022/11/16 17:00:41 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FILES = main execve gnl_manager TESTINGSTUFF utils

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILES)))

OBJS_DIR = Objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# ===---===---===---===---===---===---===---===---===---===---===---===---

LIBFT_DIR = Libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a
LIBFT_OBJS = $(LIBFT_DIR)/Objs

LIBFT = $(LIBFT_PATH)


# ===---===---===---===---===---===---===---===---===---===---===---===---

all: | $(OBJS_DIR)/ $(NAME)

$(OBJS_DIR)/:
	@mkdir $(OBJS_DIR)
	@mkdir $(OBJS_DIR)/SRCS

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(OBJS_DIR)/SRCS/%.o: SRCS/%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@mv $(<:.c=.o) $(OBJS_DIR)/SRCS

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
