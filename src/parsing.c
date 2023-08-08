#include "./include/cub3d.h"
// 맵 전체
// 캐릭터
// 텍스쳐

char	*create_line(char *str, char *needle)
{
	char	*line;
	char	*trimmedline;
	int		index;

	line = ft_strstr(str, needle);
    // printf("\nft_strstr:\n%s", line);
	if (line)
	{
		line += ft_strlen(needle);
		while (*line == ' ')
			line++;
        // printf("\nline1:\n%s\n", line);
		index = get_findex(line, '\n');
		line = ft_substr(line, 0, index);
        // printf("\nline2: %s\n", line);
		trimmedline = ft_strtrim(line, " ");
		free(line);
		return (trimmedline);
	}
    return (NULL);
}

int	parsing_color(char *full_file, unsigned int *color, char *pattern)
{
    (void)color;
	char	*line;
	char	**split;
	t_color	color_s;

	ft_bzero(&color_s, sizeof(t_color));

	line = create_line(full_file, pattern);
    // printf("\ncreate line:\n%s\n", line);
	if (!line)
		return (ft_error("\nRGB isn't found in Map\n"));
	split = ft_split(line, ',');
    // for (int i=0; split[i]; i++)
    // {
    //     printf("split%d: %s\n", i, split[i]);
    // }
    
    if (!check_rgb(split, &color_s))
	{
		Free2DArray(split);
		free(line);
        return (ft_error("ERROR\n"));
	}

    // printf("\nR: %d", color_s.R);
    // printf("\nG: %d", color_s.G);
    // printf("\nB: %d", color_s.B);
    // printf("\n");
	Free2DArray(split);
	free(line);
	*color = make_rgb(color_s.R, color_s.G, color_s.B);
	return (0);
}

int parsing_all(int fd, t_map *map_all)
{
    int ret;

    ret = read_till_end(fd, &(map_all->full_path));
    int i = 0;

    // printf("%s", map_all->full_path);
    if (ret == -1)
        return ft_error("");
    if (parsing_color(map_all->full_path, &map_all->floor_color, "F ")
		|| parsing_color(map_all->full_path, &map_all->cell_color, "C ")
        || parsing_map(map_all, map_all->full_path))
        {
            printf("hello\n");
        }

    // printf("\n");
    // printf("floor parsing\n");
    // printf("floor R: %d\n", get_r(map_all->floor_color));
    // printf("floor G: %d\n", get_g(map_all->floor_color));
    // printf("floor B: %d\n", get_b(map_all->floor_color));
    // printf("\n");
    // printf("cell parsing\n");
    // printf("cell R: %d\n", get_r(map_all->cell_color));
    // printf("cell G: %d\n", get_g(map_all->cell_color));
    // printf("cell B: %d\n", get_b(map_all->cell_color));

    return i;
}

// 들어오는 입력에 대해서 구조체에 초기화 하는 함수
int init_input(t_game *game_all, char *map_path)
{
    
    int fd;

    fd = open(map_path, O_RDONLY);
    if (fd == -1)
        return (ft_error("map isn't exist\n"));
    printf("\nmap is open\n");
    // (void)game_all;
    if (parsing_all(fd, &game_all->map))
        return (ft_error("map parsing error\n"));
    close(fd);
    printf("map is closed\n");
    return (0);
}

// 파씽 전부다 마무리하는 함수
int ft_parsing_master(char **argv, t_game *game_all)
{
    // (void)game_all;
    // printf("%s", argv[1]);

    if (init_input(game_all, argv[1]))
        return (1);
    printf("\n");
    return 0;
}