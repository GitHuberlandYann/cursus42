# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 10:15:27 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/18 10:27:58 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf ft_atoi_bonus ft_parsing_bonus ft_parsing2_bonus \
		ft_put_fd ft_put_fd2 ft_utils ft_count_bonus

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
