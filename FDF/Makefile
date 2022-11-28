# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 10:00:20 by yhuberla          #+#    #+#              #
#    Updated: 2022/11/28 17:44:33 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getmeoutofhere

NAMEB = fdf_bonus

FILE = main gnl_manager angles_manager utils mlx_utils mlx_manager mlx_events \
		animation_utils mlx_colors map2

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILE)))

OBJS = $(SRCS:.c=.o)

FILES_BONUS = main gnl_manager gnl_utils utils ft_atof

SRCS_BONUS = $(addprefix BONUS/, $(addsuffix .c, $(FILES_BONUS)))

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O3 -O2 -Os -Imlx -fsanitize=address -g

# ^^^^^^^^^^^^^ INCLUDING MINILIBX ^^^^^^^^^^^^^
MLX_DIR = mlx
MLX_PATH = ${MLX_DIR}/libmlx.a

MLX = -framework OpenGl -framework AppKit $(MLX_PATH)

# ^^^^^^^^^^^^^ INCLUDING Libft ^^^^^^^^^^^^^^^^
LIBFT_DIR = Libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a

LIBFT = $(LIBFT_PATH)

# ^^^^^^^^^^^^^ INCLUDING MATH.H ^^^^^^^^^^^^^^^
MATH = -lm

# ^^^^^^^^^^^^^ RULING AND STUFF ^^^^^^^^^^^^^^^

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(LIBFT) $(MATH)

bonus: $(OBJS_BONUS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAMEB) $(MLX) $(LIBFT) $(MATH)

clean:
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re bonus