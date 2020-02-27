# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oderkaou <oderkaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 21:43:33 by ikrkharb          #+#    #+#              #
#    Updated: 2020/02/27 16:09:36 by oderkaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libparser.a

FLAGS = -Wall -Wextra -Werror

SRC = 	parser.c\
		utils.c\
		ft_lst_ops.c\
		new_list.c\
		free.c\

OBJ = $(SRC:.c=.o)

INC = parser.h

$(NAME): $(OBJ) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c $(INC)
	gcc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
