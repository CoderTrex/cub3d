NAME = cub3d
SRCS =  main.c\
		parsing.c\
		parsing_utils.c\
		color.c\
		utils.c\
		map.c

OBJS = $(SRCS:.c=.o)
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra

all: extern $(NAME)

extern:
	make -C libft/

$(NAME): $(OBJS)
	$(COMPILER) -o $(NAME) $(OBJS) \
	libft/libft.a 

%.o: %.c ./include/cub3d.h
	$(COMPILER) $(CFLAGS) -c $<

clean:
	make clean -C libft/
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all extern clean fclean re