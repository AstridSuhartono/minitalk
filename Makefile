# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astrid <astrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 13:35:59 by astrid            #+#    #+#              #
#    Updated: 2022/07/10 00:39:45 by astrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = gcc
CFLAGS = -Werror -Wall -Wextra -C
RM = rm -rf

SRCS = client.c server.c printf/libftprintf.a
#SRCS_BONUS = bonus/client.c bonus/server.c printf/libftprintf.a

$(NAME):
	make all -C printf
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)
	make clean -C printf

fclean: clean
	$(RM) $(NAME)
	make clean -C printf

re: fclean all

bonus: clean
	make all -C printf
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)

bonus_re: fclean bonus

.PHONY: all bonus clean fclean re bonus_re