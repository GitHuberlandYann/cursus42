# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 16:48:46 by yhuberla          #+#    #+#              #
#    Updated: 2023/03/15 16:50:55 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapons
OBJS_DIR = Objs

FILES = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
SRCS = $(addprefix Sources/, $(FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

# ===---===---===---===---===---===---===---===---===---===---===---===---

CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -std=c++98
INCLUDES = -I Includes

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/Sources

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.cpp
	c++ $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
