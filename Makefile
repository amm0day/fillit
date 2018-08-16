# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 14:33:05 by pguthaus          #+#    #+#              #
#    Updated: 2018/08/16 20:08:05 by sungurea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = cc# C compiler
CFLAGS = -I ./include/ -Wall -Werror -Wextra# C compiler flags

RESET = \033[0m
PURPLE = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m

# Paths
# Paths

SRCS =		main.c			\
			src/ft_swap.c 	\
			src/parsing.c	\
			src/printstruct.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	@echo "$(YELLOW)Deleting objects files...$(RESET)"
	@rm -rf $(OBJS)
	@echo "$(GREEN)Object files (based in 'src/') have been deleted !$(RESET)"

fclean: clean
	@echo "$(YELLOW)Deleting executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)The executable '$(NAME)' has been deleted !$(RESET)"

re: fclean all

.PHONY: re fclean clean
