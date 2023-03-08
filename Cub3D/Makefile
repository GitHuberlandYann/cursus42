# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 12:34:39 by yhuberla          #+#    #+#              #
#    Updated: 2023/02/19 17:20:57 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
OBJS_DIR = Objs
OBJS_DIR_SOURCES = Objs/Sources

FILES = main

FILES_FDF = angles parse_obj parse_pos parse_utils rendering

FILES += $(addprefix Fdf/, $(FILES_FDF))

FILES_GRAPHICS = animation exec_keys image keys math_utils \
				minimap mlx_manager mouse \
				rendering timer

FILES += $(addprefix Graphics/, $(FILES_GRAPHICS))

FILES_MULTIPLAYER = animation exec_keys keys load_images precompute weapons

FILES += $(addprefix MultiPlayer/, $(FILES_MULTIPLAYER))

FILES_OUTPUTS = debug error

FILES += $(addprefix Outputs/, $(FILES_OUTPUTS))

FILES_PARSING = add_wall animated_wall animation colors custom doors \
				flood_fill free header map map_content objects players portals \
				portals_utils posts textures walls window

FILES += $(addprefix Parsing/, $(FILES_PARSING))

FILES_RAYCASTING = floor_casting precompute ray_casting ray_dooring ray_objing \
					ray_portaling ray_posting

FILES += $(addprefix RayCasting/, $(FILES_RAYCASTING))

Sources = $(addprefix Sources/, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix $(OBJS_DIR)/, $(Sources:.c=.o))

# ===---===---===---===---===---===---===---===---===---===---===---===---

ifeq ($(shell uname), Linux)
MLX_DIR = mlx_linux
MLX_PATH = ${MLX_DIR}/libmlx.a
MLX = -lmlx_linux -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(MLX_PATH)
INCLUDES = -I Includes -I mlx_linux
else
MLX_DIR = mlx
MLX_PATH = ${MLX_DIR}/libmlx.a
MLX = -lmlx -Lmlx -framework OpenGl -framework AppKit $(MLX_PATH)
INCLUDES = -I Includes -I mlx
endif

# ===---===---===---===---===---===---===---===---===---===---===---===---

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
SAN = -fsanitize=address -g
MATH = -lm

# ===---===---===---===---===---===---===---===---===---===---===---===---

LIBFT_DIR = Libft
LIBFT_OBJS = $(LIBFT_DIR)/Objs

LIBFT = $(LIBFT_DIR)/libft.a

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR_SOURCES)
	@mkdir -p $(OBJS_DIR_SOURCES)/Fdf
	@mkdir -p $(OBJS_DIR_SOURCES)/Graphics
	@mkdir -p $(OBJS_DIR_SOURCES)/MultiPlayer
	@mkdir -p $(OBJS_DIR_SOURCES)/Outputs
	@mkdir -p $(OBJS_DIR_SOURCES)/Parsing
	@mkdir -p $(OBJS_DIR_SOURCES)/RayCasting

$(NAME): $(OBJS) libs
	$(CC) $(SAN) $(OBJS) -o $(NAME) $(MLX) $(LIBFT) $(MATH)

$(OBJS_DIR_SOURCES)/%.o: Sources/%.c
	$(CC) $(CFLAGS) $(SAN) $(INCLUDES) -c $< -o $@

libs:
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	#make clean -C $(MLX_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libs
