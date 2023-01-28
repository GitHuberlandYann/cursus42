# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:26:44 by yhuberla          #+#    #+#              #
#    Updated: 2023/01/28 12:55:07 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
OBJS_DIR = Objs
OBJS_DIR_SOURCES = Objs/Sources

FILES = death main mutex outputs parsing threads

Sources = $(addprefix Sources/, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix $(OBJS_DIR)/, $(Sources:.c=.o))

# ===---===---===---===---===---===---===---===---===---===---===---===---

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
THREAD_LIB = -lpthread
INCLUDES = -I Includes

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: $(OBJS_DIR_SOURCES) $(NAME)

$(OBJS_DIR_SOURCES):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/Sources

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME) $(THREAD_LIB)

$(OBJS_DIR)/Sources/%.o: Sources/%.c
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)
	@mv $(<:.c=.o) $(OBJS_DIR)/Sources

run: all
	./philo

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re Objs/Sources philo
