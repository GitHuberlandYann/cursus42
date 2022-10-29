# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 15:35:23 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/29 02:02:22 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushtheswap

CHECKER = checker

FILES = main enigma stack utils small big \
		sort_no_b sort_selection sort_bubble sort_insertion \
		sort_section_selection sort_section_insertion

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILES)))

OBJS = $(SRCS:.c=.o)

BONUS_FILES = main stack arg_parser gnl_manager execution

BONUS_SRCS = $(addprefix Bonus/, $(addsuffix .c, $(BONUS_FILES)))

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

# ^^^^^^^^^^^^^ INCLUDING Libft ^^^^^^^^^^^^^^^^
LIBFT_DIR = Libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a

LIBFT = $(LIBFT_PATH)

# ^^^^^^^^^^^^^ RULING AND STUFF ^^^^^^^^^^^^^^^

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

bonus: $(BONUS_OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(CHECKER) $(LIBFT)

clean:
	make fclean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re