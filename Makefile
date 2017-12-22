# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/22 18:05:36 by nkamolba          #+#    #+#              #
#    Updated: 2017/12/22 18:14:24 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FILE = main.c graph.c queue.c
FILE_O = $(FILE:%.c=%.o)

all : $(NAME)

$(NAME) : $(FILE_O)
	gcc $(FLAG) -o $(NAME) $(FILE_O)

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	rm -f $(FILE_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
