SRC =	srcs/ft_check.c						\
		srcs/ft_exit.c						\
		srcs/ft_input.c						\
		srcs/ft_map.c						\
		srcs/ft_mlx.c						\
		srcs/ft_utils.c						\
		srcs/get_next_line.c				\
		srcs/get_next_line_utils.c			\
		srcs/ft_check2.c					\
		srcs/main.c							\

BSRC = 	bonus/ft_animation_bonus.c			\
		bonus/ft_check_bonus.c				\
		bonus/ft_exit_bonus.c				\
		bonus/ft_input_bonus.c				\
		bonus/ft_map_bonus.c				\
		bonus/ft_mlx_bonus.c				\
		bonus/ft_utils_bonus.c				\
		bonus/get_next_line_bonus.c			\
		bonus/get_next_line_utils_bonus.c	\
		bonus/ft_check2_bonus.c				\
		bonus/main_bonus.c					\

OBG = $(SRC:.c=.o)
BOBG = $(BSRC:.c=.o)

NAME = so_long
BNAME = so_long_bonus

I = -I ./includes/

L = -L . -lmlx_Linux -lX11 -lXext
FLAGS = -Wall -Wextra -Werror

all: mlx $(NAME)
bonus: mlx $(BNAME)

$(NAME): $(OBG)
	cc $(OBG) $(L) -o $@

$(BNAME): $(BOBG)
	cc $(BOBG) $(L) -o $@

$(OBG): %.o: %.c ./includes/get_next_line.h ./includes/so_long.h
	cc -c $(FLAGS) $(I) $< -o $@

$(BOBG): %.o: %.c ./includes/get_next_line_bonus.h ./includes/so_long_bonus.h
	cc -c $(FLAGS) $(I) $< -o $@

clean:
	rm -f $(OBG) $(BOBG)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: clean mlx

mlx: libmlx_Linux.a

libmlx_Linux.a:
	rm -fr minilibx-linux; \
	tar -xvzf minilibx-linux.tgz; \
	cd minilibx-linux && make; \
	cd ..; \
	mv minilibx-linux/libmlx_Linux.a .; \
	cp minilibx-linux/mlx.h ./includes/; \
	rm -fr minilibx-linux;
