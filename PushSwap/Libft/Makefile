# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 08:48:24 by yhuberla          #+#    #+#              #
#    Updated: 2022/10/28 17:52:33 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = get_next_line_utils get_next_line \
		ft_strlen ft_arraylen ft_split ft_atoi ft_strcmp \
		ft_printf ft_printf_output ft_printf_output2 ft_printf_utils \
		ft_lstadd_back ft_lstclear ft_lstdelone ft_lstnew

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

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
