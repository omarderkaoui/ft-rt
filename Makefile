# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oderkaou <oderkaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 20:53:05 by ikrkharb          #+#    #+#              #
#    Updated: 2020/02/27 15:57:33 by oderkaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

FLAGS = -Wall -Werror -Wextra

SRCS = 	srcs/ray_gen.c\
		srcs/fill_data.c\
		srcs/hooks.c\
		srcs/parsing.c\
		srcs/rtv1.c\
		srcs/vectors_ops.c\
		srcs/objects.c\
		srcs/intersection.c\
		srcs/utils.c \
		srcs/color.c\
		srcs/phong_model.c\
		srcs/shadow.c\
		srcs/normal.c\
		checker-yaml/checker.c\
		checker-yaml/check_keys.c\
		checker-yaml/checker_utils.c\
		srcs/transform.c\
		srcs/init_env.c\
		srcs/mlx.c\
		srcs/parsing_utils.c\
		srcs/rotate_axes.c\
		srcs/vec_scaling.c\
		checker-yaml/check_input.c\
		checker-yaml/check_input_utils.c\
		checker-yaml/check_shapes.c\

LIBFT = libft/libft.a

LIBPS = parser-yaml/libparser.a

INC = includes/rtv1.h

OBJ = $(SRCS:.c=.o)

all: lib $(NAME)

lib:
	@make -C libft > /dev/null
	@make -C parser-yaml > /dev/null

$(NAME): $(OBJ) $(INC)
	@gcc $(FLAGS) -I usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit $(OBJ) $(LIBFT) $(LIBPS) -o $(NAME)
	@echo "\033[92mDone\033[0m"

%.o: %.c $(INC)
	gcc $(FLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C parser-yaml
	@/bin/rm -rf $(OBJ) > /dev/null
	@echo "\033[92mCleaning done\033[0m"

fclean: clean
	@make fclean -C libft
	@make fclean -C parser-yaml
	@/bin/rm -rf $(NAME)
	@echo "\033[92mExecution and cleaning were done\033[0m"

re: fclean all
