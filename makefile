# NAME = cub3d

# SRCS =  src/main.c\
# 		src/parsing/parsing.c\
# 		src/parsing/parsing_utils.c\
# 		src/parsing/color.c\
# 		src/parsing/utils.c\
# 		src/parsing/map.c

# OBJS = $(SRCS:.c=.o)
# COMPILER = cc
# CFLAGS = -Wall -Werror -Wextra

# all: extern $(NAME)

# extern:
# 	make -C libft/

# $(NAME): $(OBJS)
# 	$(COMPILER) -o $(NAME) $(OBJS) \
# 	libft/libft.a 

# %.o: %.c ./include/cub3d.h
# 	$(COMPILER) $(CFLAGS) -c $<

# clean:
# 	make clean -C libft/
# 	rm -rf $(OBJS)

# fclean: clean
# 	rm -rf libft/libft.a
# 	rm -rf $(NAME)

# re: fclean all

# .PHONY: all extern clean fclean re

NAME = cub3d

SRCS =  src/main.c\
		src/parsing/parsing.c\
		src/parsing/parsing_utils.c\
		src/parsing/color.c\
		src/parsing/utils.c\
		src/parsing/map.c\
		src/mlx/init_game.c

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
