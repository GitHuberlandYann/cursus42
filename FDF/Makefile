# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 10:00:20 by yhuberla          #+#    #+#              #
#    Updated: 2022/12/09 14:15:12 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NAMEB = fdf_bonus

NAMEE = fdf_edit

FILE = main gnl_manager angles_manager utils mlx_utils mlx_manager mlx_events \
		animation_utils mlx_colors map2

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILE)))

OBJS = $(SRCS:.c=.o)

FILES_BONUS = main gnl_manager gnl_utils utils mlx_manager mlx_events mlx_draw \
				mlx_img angles_manager

SRCS_BONUS = $(addprefix BONUS/, $(addsuffix .c, $(FILES_BONUS)))

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

FILES_EDIT = main angles_manager map_utils map mlx_draw mlx_edit mlx_events \
				mlx_img mlx_manager utils mlx_colors mlx_fill mlx_fill_utils


SRCS_EDIT = $(addprefix EDIT/, $(addsuffix .c, $(FILES_EDIT)))

OBJS_EDIT = $(SRCS_EDIT:.c=.o)

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

edit: $(OBJS_EDIT)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS_EDIT) -o $(NAMEE) $(MLX) $(LIBFT) $(MATH)

clean:
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS) $(OBJS_BONUS) $(OBJS_EDIT)

fclean: clean
	rm -f $(NAME) $(NAMEB) $(NAMEE)

re: fclean all

.PHONY: all clean fclean re bonus edit NAME