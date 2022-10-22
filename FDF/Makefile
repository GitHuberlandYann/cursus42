# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 10:00:20 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/22 14:23:02 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getmeoutofhere

FILE = main gnl_manager utils # mlx_manager

SRCS = $(addsuffix .c, $(FILE))

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Imlx

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = mlx
MLX_PATH = ${MLX_DIR}/libmlx.a

MLX = -framework OpenGl -framework AppKit $(MLX_PATH)

# /* ~~~~~~~ INCLUDING Libft ~~~~~~~~~~ */
LIBFT_DIR = Libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a

LIBFT = $(LIBFT_PATH)

# /* ~~~~~~~ RULING AND STUFF ~~~~~~~~~ */

all: $(NAME)

$(NAME): $(OBJS)
	# @make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) #$(MLX) $(LIBFT)
	make fclean -C $(LIBFT_DIR)
	# make clean -C $(MLX_DIR)
	rm -f $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean