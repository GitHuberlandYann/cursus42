# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 13:18:11 by yhuberla          #+#    #+#              #
#    Updated: 2022/11/02 13:18:11 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

FILES = arg_parser enigma index_insert insert longest_subseq push_unwanted \
		sort_big sort_small stack stack2 utils main

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix Objs/, $(SRCS:.c=.o))

DIR_OBJ = Objs
DIR_OBJ_SRCS = Objs/SRCS
DIR_OBJ_BONUS = Objs/Bonus

BONUS_FILES = main stack arg_parser gnl_manager execution

BONUS_SRCS = $(addprefix Bonus/, $(addsuffix .c, $(BONUS_FILES)))

BONUS_OBJS = $(addprefix Objs/, $(BONUS_SRCS:.c=.o))

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

# ^^^^^^^^^^^^^ INCLUDING Libft ^^^^^^^^^^^^^^^^
LIBFT_DIR = Libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a

LIBFT = $(LIBFT_PATH)

# ^^^^^^^^^^^^^ RULING AND STUFF ^^^^^^^^^^^^^^^

all: | $(DIR_OBJ)/ $(NAME)

$(DIR_OBJ)/:
	@mkdir $(DIR_OBJ)

$(NAME): | $(DIR_OBJ_SRCS)/ $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(DIR_OBJ_SRCS)/:
	@mkdir $(DIR_OBJ_SRCS)

$(DIR_OBJ_SRCS)/%.o: SRCS/%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@mv $(<:.c=.o) $(DIR_OBJ_SRCS)

bonus: | $(DIR_OBJ_BONUS)/ $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(CHECKER) $(LIBFT)

$(DIR_OBJ_BONUS)/: | $(DIR_OBJ)/
	@mkdir $(DIR_OBJ_BONUS)

$(DIR_OBJ_BONUS)/%.o: Bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@mv $(<:.c=.o) $(DIR_OBJ_BONUS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re
