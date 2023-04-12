# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 11:24:10 by yhuberla          #+#    #+#              #
#    Updated: 2023/04/12 11:24:10 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify
OBJS_DIR = Objs

FILES = main
SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(SRCS:.cpp=.o)

# ===---===---===---===---===---===---===---===---===---===---===---===---

CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -std=c++98

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	c++ $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
