# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 12:41:01 by yhuberla          #+#    #+#              #
#    Updated: 2022/11/28 14:29:55 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_split ft_arrayadd_back ft_arraylen ft_strjoin ft_strjoins ft_strlen \
		ft_strcmp ft_strncmp ft_putstr_fd ft_strdup ft_itoa \
		get_next_line get_next_line_utils \
		ft_lstadd_back ft_lstclear ft_lstdelone ft_lstnew

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix ../Objs/Libft/, $(SRCS:.c=.o))

DIR_OBJ = ../Objs/Libft

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = gcc

all: $(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(DIR_OBJ)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@mv $(<:.c=.o) $(DIR_OBJ)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
