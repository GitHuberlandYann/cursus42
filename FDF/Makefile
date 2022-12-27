# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 10:00:20 by yhuberla          #+#    #+#              #
#    Updated: 2022/12/27 12:53:34 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NAMEB = fdf_bonus

NAMEE = fdf_edit

FILE = main angles_manager map_utils map mlx_colors mlx_draw mlx_keys \
		mlx_fill_utils mlx_fill mlx_img mlx_manager mlx_utils utils mlx_mouse

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILE)))

OBJS = $(SRCS:.c=.o)

FILES_BONUS = main gnl_manager gnl_utils utils mlx_manager mlx_events mlx_draw \
				mlx_img angles_manager mlx_fill mlx_fill_utils

SRCS_BONUS = $(addprefix BONUS/, $(addsuffix .c, $(FILES_BONUS)))

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

FILES_EDIT = main angles_manager map_utils map mlx_draw mlx_edit mlx_events \
				mlx_img mlx_manager utils mlx_colors mlx_fill mlx_fill_utils


SRCS_EDIT = $(addprefix EDIT/, $(addsuffix .c, $(FILES_EDIT)))

OBJS_EDIT = $(SRCS_EDIT:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O3 -Imlx

# ^^^^^^^^^^^^^ INCLUDING MINILIBX ^^^^^^^^^^^^^
MLX_DIR = mlx
MLX_PATH = ${MLX_DIR}/libmlx.a

MLX = -lmlx -Lmlx -framework OpenGl -framework AppKit $(MLX_PATH)

# ^^^^^^^^^^^^^ INCLUDING Libft ^^^^^^^^^^^^^^^^
LIBFT_DIR = Libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a

LIBFT = $(LIBFT_PATH)

# ^^^^^^^^^^^^^ INCLUDING MATH.H ^^^^^^^^^^^^^^^
MATH = -lm

# ^^^^^^^^^^^^^ RULING AND STUFF ^^^^^^^^^^^^^^^

all: $(NAME)

$(NAME): $(OBJS) libs
	$(CC) $(OBJS) -o $(NAME) $(MLX) $(LIBFT) $(MATH)

bonus: $(OBJS_BONUS) libs
	$(CC) $(OBJS_BONUS) -o $(NAMEB) $(MLX) $(LIBFT) $(MATH)

edit: $(OBJS_EDIT) libs
	$(CC) $(OBJS_EDIT) -o $(NAMEE) $(MLX) $(LIBFT) $(MATH)

libs:
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS) $(OBJS_BONUS) $(OBJS_EDIT)

fclean: clean
	rm -f $(NAME) $(NAMEB) $(NAMEE)

re: fclean all

.PHONY: all clean fclean re bonus edit NAME libs