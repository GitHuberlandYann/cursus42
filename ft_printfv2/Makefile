# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 16:12:45 by yhuberla          #+#    #+#              #
#    Updated: 2022/11/18 11:53:22 by yhuberla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS_DIR = OBJS

FILES = ft_printf

SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILES)))

SRCS_OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

SRCS_OBJS_DIR = $(OBJS_DIR)/SRCS

# =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

all: dir_objs_srcs $(NAME)

dir_objs_srcs: dir_objs
	@mkdir -p $(SRCS_OBJS_DIR)

dir_objs:
	@mkdir -p $(OBJS_DIR)

$(NAME): $(SRCS_OBJS)
	ar -rcs $(NAME) $(SRCS_OBJS)

$(SRCS_OBJS_DIR)/%.o: SRCS/%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@mv $(<:.c=.o) $(SRCS_OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all dir_objs dir_objs_srcs clean fclean re
