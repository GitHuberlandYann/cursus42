# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 15:35:23 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/27 16:19:41 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushtheswap

FILE = main enigma

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILE)))

OBJS = $(SRCS:.c=.o)

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

clean:
	make fclean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re