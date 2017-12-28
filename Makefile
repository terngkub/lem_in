# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/22 18:05:36 by nkamolba          #+#    #+#              #
#    Updated: 2017/12/28 17:54:41 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAG = -Wall -Wextra -Werror
LIB = -Llibft -lft
LIBFT = libft/libft.a

FILE = main.c node.c utils.c read_input.c read_room.c read_link.c get_path.c\
	   bfs.c cleaning.c move_ant.c

FILE_O = $(FILE:%.c=%.o)

all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME) : $(FILE_O) | $(LIBFT)
	gcc $(FLAG) -o $(NAME) $(FILE_O) $(LIB)

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(FILE_O)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
