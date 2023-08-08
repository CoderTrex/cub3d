#include "./include/cub3d.h"

int ft_error(char *msg)
{
    printf("%s", msg);
    return 1;
}

void leak_check()
{
    system("leaks cub3d");
}

int main(int argc, char **argv)
{
    (void)argv;
    t_game   game_all;

    ft_bzero(&game_all, sizeof(game_all));
    if (argc != 2)
        return (ft_error("argc is must be 2\n"));
    if (ft_parsing_master(argv, &game_all))
        return (1);
    atexit(leak_check);
    return (0);
}