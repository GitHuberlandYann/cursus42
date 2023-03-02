# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 12:48:52 by yhuberla          #+#    #+#              #
#    Updated: 2023/03/02 15:22:42 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_arraylen ft_atoi ft_atoi_64bits ft_bzero ft_fmod ft_free_arr \
		ft_itoa ft_malloc ft_perror ft_putendl ft_split ft_split_first \
		ft_split_quotes ft_split_quotes_set ft_strchr ft_strchr_cntset \
		ft_strchr_quotes ft_strcat ft_strcpy ft_strdup ft_strjoin ft_strjoins \
		ft_strlen ft_strncmp get_next_line_utils get_next_line

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix ../Objs/Libft/, $(SRCS:.c=.o))

DIR_OBJ = ../Objs/Libft

# ===---===---===---===---===---===---===---===---===---===---===---===---

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: $(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(DIR_OBJ)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
