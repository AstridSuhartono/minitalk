# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astrid <astrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 13:35:59 by astrid            #+#    #+#              #
#    Updated: 2022/07/10 21:35:33 by astrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@cd printf && make all
	@gcc -Wall -Wextra -Werror server.c utils.c printf/libftprintf.a -o server
	@gcc -Wall -Wextra -Werror client.c utils.c printf/libftprintf.a -o client

bonus:
	@cd printf && make all
	@gcc -Wall -Wextra -Werror server_bonus.c utils.c printf/libftprintf.a -o server
	@gcc -Wall -Wextra -Werror client_bonus.c utils.c printf/libftprintf.a -o client

clean:
	@cd printf && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd printf && make fclean

re: fclean all
