#include "../../include/cub3d.h"
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
    
    if (check_rgb(split, &color_s))
	{
		Free2DArray(split);
		free(line);
        return (ft_error("\nRGB: ERROR\n"));
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

char *removeSpaces(char *input)
{
    int j = 0;
    char *output;
 
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ' && input[i] > 0) {
            // printf("test : %c\n", input[i]);
            // printf("test : %d\n", input[i]);
            j++;
        }
    }
    output = malloc(sizeof(char *) * j);
    
    j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ' && input[i] > 0) {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0'; // 문자열의 끝을 나타내기 위해 널 문자를 추가
    return (output);
}

int	parsing_texture(t_map *map, t_img *img)
{
    // img->north = create_line(map->full_path, "NO ");
    // img->east = create_line(map->full_path, "EA ");
    // img->west = create_line(map->full_path, "WE ");
    // img->south = create_line(map->full_path, "SO ");

    char *tmp[4];

    tmp[0] = create_line(map->full_path, "NO ");
    tmp[1] = create_line(map->full_path, "EA ");
    tmp[2] = create_line(map->full_path, "WE ");
    tmp[3] = create_line(map->full_path, "SO ");
    
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%s\n", tmp[i]);
    // }

    img->north = removeSpaces(tmp[0]);
    img->east = removeSpaces(tmp[1]);
    img->west = removeSpaces(tmp[2]);
    img->south = removeSpaces(tmp[3]);

    free(tmp[0]);
    free(tmp[1]);
    free(tmp[2]);
    free(tmp[3]);

    // printf("%s\n", img->north);
    // printf("%s\n", img->east);
    // printf("%s\n", img->west);
    // printf("%s\n", img->south);
	if (!(img->north) || !(img->west)
		|| !(img->south) || !(img->east))
		return (ft_error("path is wrong\n"));
	return (0);
}

int parsing_all(int fd, t_game *game_all, t_map *map_all)
{
    int ret;

    ret = read_till_end(fd, &(map_all->full_path));
    int i = 0;

    // printf("%s", map_all->full_path);
    if (ret == -1)
        return ft_error("");
    if (parsing_color(map_all->full_path, &map_all->floor_color, "F ")
		|| parsing_color(map_all->full_path, &map_all->cell_color, "C ")
        || parsing_map(map_all, map_all->full_path) // 문제점 2차원 배열을 null일 때까지 접근하면 segmentfault가 뜨는데 왜 그런지 모르겠음
        || parsing_texture(map_all, &game_all->img))
        {
            printf("map format is wrong\n");
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
    if (parsing_all(fd, game_all, &game_all->map))
        return (ft_error("map parsing error\n"));
    close(fd);
    printf("map is closed\n");
    return (0);
}

// 파씽 전부다 마무리하는 함수
int ft_parsing_master(char **argv, t_game *game_all)
{
    // (void)argv;
    // (void)game_all;
    // printf("%s", argv[1]);

    if (init_input(game_all, argv[1]))
        return (1);
    // printf("-------------TEST-------------\n");
    // printf("TEXTURE\n");
    // printf("NORTH %s\n", game_all->img.north);
    // printf("WEST %s\n", game_all->img.west);
    // printf("SOUTH %s\n", game_all->img.south);
    // printf("EAST %s\n", game_all->img.east);
    // printf("\n\n");

    // printf("FLOOR COLOR\n");
    // printf("R: %d ", get_r(game_all->map.floor_color));
    // printf("G: %d ", get_g(game_all->map.floor_color));
    // printf("B: %d ", get_b(game_all->map.floor_color));
    // printf("\n");
    // printf("CELL COLOR\n");
    // printf("R: %d ", get_r(game_all->map.cell_color));
    // printf("G: %d ", get_g(game_all->map.cell_color));
    // printf("B: %d ", get_b(game_all->map.cell_color));
    // printf("\n\n");
    
    // printf("MAP and MAP height and width\n");
    // int i = -1;
    // while (++i < game_all->map.map_len)
    //     printf("%s\n", game_all->map.map[i]);
    // printf("height: %d ", game_all->map.height);
    // printf("width : %d ", game_all->map.width);
    // printf("\n\n");
    
    // printf("CHARACTER POSITION\n");
    // printf("x: %d, y: %d\n", game_all->map.px, game_all->map.py);
    // printf("position: %c", game_all->map.pos);
    // printf("\n\n");

    // 나중에 전부다 free하는 함수 만들어야겠다.
    free(game_all->map.full_path);
    free(game_all->img.east);
    free(game_all->img.north);
    free(game_all->img.south);
    free(game_all->img.west);
    // Free2DArray(game_all->map.map);
	
    int count = 0;
	if (game_all->map.map)
	{
		while (count < game_all->map.map_len)
		{
            free(game_all->map.map[count]);
            free(game_all->map.map_cp[count]);
            free(game_all->map.map_cp2[count]);
			count++;
		}
		free(game_all->map.map);
		free(game_all->map.map_cp);
		free(game_all->map.map_cp2);
	}
    
    printf("\n");
    return 0;
}