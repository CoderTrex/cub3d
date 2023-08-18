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
		src/parsing/map.c

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))
COMPILER = cc
CFLAGS = -g -Wall -Werror -Wextra

all: extern $(NAME)

extern:
	make -C libft/

$(NAME): $(OBJS)
	$(COMPILER) -o $(NAME) $(OBJS) \
	libft/libft.a 

obj/%.o: src/%.c ./include/cub3d.h
	mkdir -p $(dir $@)
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft/
	rm -rf obj
	rm -rf $(NAME)

fclean: clean
	make fclean -C libft/

re: fclean all

.PHONY: all extern clean fclean re
