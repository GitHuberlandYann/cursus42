# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 08:48:24 by yhuberla          #+#    #+#              #
#    Updated: 2022/11/03 13:35:53 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = get_next_line_utils get_next_line \
		ft_arraylen ft_arrayset ft_atoi ft_maxminabs ft_split ft_strcmp \
		ft_strlen \
		ft_printf ft_printf_output ft_printf_output2 ft_printf_utils \
		ft_lstadd_back ft_lstclear ft_lstdelone ft_lstnew

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
