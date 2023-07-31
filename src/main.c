#include <unistd.h>
#include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

#  define BUFFER_SIZE 42

typedef struct s_character
{
} t_character;

typedef struct s_info
{
    char *full_path;
} t_info;

typedef struct s_data
{
    t_character character;
    t_info info;
} t_data;

int ft_error(char *msg)
{
    printf("%s", msg);
    return 1;
}

int read_till_end(int fd, char **path)
{
    int             ret;
    static char     buf[BUFFER_SIZE + 1];

    if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !path)
        return (-1);
    *path;
    ret = 1;
    while (ret > 0)
    {
        *path = ft_join(*path, buf);
        ret = read(fd, buf, BUFFER_SIZE);
        if (ret == -1)
            return (-1);
        buf[ret] = '\0';
    }
    return (0);
}


int parsing_all(int fd, t_info *info)
{
    int ret;

    ret = read_till_end(fd, &(info->full_path));
    if (ret == -1)
        return ft_error("");

    printf("%s", info->full_path);
}


int init_input(t_data *game, char *map_path)
{
    int fd;

    fd = open(map_path, O_RDONLY);
    if (fd == -1)
        return (ft_error("map isn't exist\n"));
    if (parsing_all(fd, &game->info))
        return (ft_error("map parsing error\n"));
    return (0);
}

int ft_parsing_master(char **argv, t_data *game)
{
    int fd;
    if (init_input(game, argv[1]))
        return (1);
    return 0;
}

int main(int argc, char **argv)
{
    t_data game;

    if (argc != 2)
        return (ft_error("argc is must be 2\n"));
    if (ft_parsing_master(argv, &game))
        return (1);

    return (0);
}