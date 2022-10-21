# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 10:00:20 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/21 15:44:19 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getmeoutofhere

FILE = main mlx_manager

SRCS = $(addsuffix .c, $(FILE))

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Imlx

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = mlx
MLX_PATH = ${MLX_DIR}/libmlx.a

MLX = -framework OpenGl -framework AppKit $(MLX_PATH)

# /* ~~~~~~~ INCLUDING GNL ~~~~~~~~~~~~ */
GNL_DIR = GNL
GNL_PATH = $(GNL_DIR)/gnl.a

GNL = $(GNL_PATH)

# /* ~~~~~~~ RULING AND STUFF ~~~~~~~~~ */

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(GNL_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(GNL)
	make fclean -C $(GNL_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(NAME)

.PHONY: all