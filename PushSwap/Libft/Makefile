# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 08:48:24 by yhuberla          #+#    #+#              #
#    Updated: 2022/11/12 15:26:54 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = get_next_line_utils get_next_line \
		ft_arraylen ft_arrayset ft_atoi ft_maxminabs ft_split ft_strcmp \
		ft_strlen \
		ft_printf ft_printf_output ft_printf_output2 ft_printf_utils \
		ft_lstadd_back ft_lstclear ft_lstnew

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix Objs/, $(SRCS:.c=.o))

DIR_OBJ = Objs

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = gcc

all: | $(DIR_OBJ)/ $(NAME)

$(DIR_OBJ)/:
	@mkdir $(DIR_OBJ)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(DIR_OBJ)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@mv $(<:.c=.o) $(DIR_OBJ)

clean:
	@rm -rf Objs

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
