SRC =	srcs/ft_check.c				\
		srcs/ft_exit.c		 		\
		srcs/ft_input.c				\
		srcs/ft_map.c 				\
		srcs/ft_mlx.c 				\
		srcs/ft_utils.c 			\
		srcs/get_next_line.c 		\
		srcs/get_next_line_utils.c 	\
		srcs/main.c					\

OBJ = $(SRC:.c=.o)

NAME = so_long

I = -I./includes
L = -L./libraries -lmlx_Linux -lX11 -lXext
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) $(L) -o $@

%.o: %.c
	cc $(FLAGS) $(I) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx

mlx:
	rm -fr minilibx-linux
	tar -xvzf minilibx-linux.tgz
	cd minilibx-linux && make
	cd ..
	mv minilibx-linux/libmlx_Linux.a ./libraries/
	cp minilibx-linux/mlx.h ./includes/
	rm -fr minilibx-linux