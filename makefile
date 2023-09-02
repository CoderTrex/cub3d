NAME = cub3d

SRCS =  src/main.c\
		src/parsing/parsing.c\
		src/parsing/parsing_utils.c\
		src/parsing/color.c\
		src/parsing/utils.c\
		src/parsing/utils2.c\
		src/parsing/map_utils.c\
		src/parsing/map_utils2.c\
		src/parsing/map.c\
		src/parsing/check_map.c\
		src/mlx/init_game.c\
		src/mlx/exit_game.c\
		src/mlx/key_hook.c\
		src/mlx/mlx_utils.c\
		src/mlx/move_player.c\
		src/mlx/raycast.c\
		src/mlx/render.c

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

CC			=	cc
CFLAGS		=	-g -Wall -Werror -Wextra
CLIB		=	-Lmlx -lmlx -framework OpenGL -framework Appkit

MLX			=	mlx/
MLX_LIB		=	$(MLX)libmlx.a

all: extern $(NAME)

extern:
	make -C $(MLX) all
	make -C libft/

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CLIB) $(OBJS) \
	libft/libft.a 

obj/%.o: src/%.c ./include/cub3d.h
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(MLX)
	make clean -C libft/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(MLX)
	make fclean -C libft/
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all extern clean fclean re
