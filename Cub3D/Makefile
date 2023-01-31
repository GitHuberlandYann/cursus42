# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 12:34:39 by yhuberla          #+#    #+#              #
#    Updated: 2023/01/31 12:47:11 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
OBJS_DIR = Objs
OBJS_DIR_SOURCES = Objs/Sources

FILES = main

Sources = $(addprefix Sources/, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix $(OBJS_DIR)/, $(Sources:.c=.o))

# ===---===---===---===---===---===---===---===---===---===---===---===---

MLX_DIR = mlx
MLX_PATH = ${MLX_DIR}/libmlx.a

MLX = -lmlx -Lmlx -framework OpenGl -framework AppKit $(MLX_PATH)


# ===---===---===---===---===---===---===---===---===---===---===---===---

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
SAN = -fsanitize=address -g
INCLUDES = -I Includes -I mlx
MATH = -lm

# ===---===---===---===---===---===---===---===---===---===---===---===---

LIBFT_DIR = Libft
LIBFT_OBJS = $(LIBFT_DIR)/Objs

LIBFT = $(LIBFT_DIR)/libft.a

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: $(OBJS_DIR_Sources) $(NAME)

$(OBJS_DIR_Sources):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/Sources

$(NAME): $(OBJS) libs
	$(CC) $(SAN) $(OBJS) -o $(NAME) $(MLX) $(LIBFT) $(MATH)

$(OBJS_DIR)/Sources/%.o: Sources/%.c
	$(CC) $(CFLAGS) $(SAN) $(INCLUDES) -c $< -o $@

libs:
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libs
