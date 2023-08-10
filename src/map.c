#include "./include/cub3d.h"

int	find_map(char *full_file, t_map *info)
{

    char    **check;
    int     number = 0;
    int     total  = -1;
    int     size = 0;
    int     i = -1;

    check = ft_split(full_file, '\n');
    // printf("test\n");
    // printf("test\n");
    while (check[++total]);
        // printf("\n%s", check[total]);
    // printf("test\n");
    // printf("test\n");
    size = total - 5;
    while (check[++i])
    {
        // printf("check: %d, %s\n", i, check[i]);
        if (ft_strstr(check[i], "NO") || ft_strstr(check[i], "EA")
            || ft_strstr(check[i], "SO") || ft_strstr(check[i], "WE")
            || ft_strstr(check[i], "F ") || ft_strstr(check[i], "C "))
                number++;
        if (number == 6 && ft_strchr(check[i], '1'))
        {
            // (void)info;
            // printf("size: %d\n", size);
            info->map = (char **)malloc(sizeof(char *) * size);
            info->map_cp = (char **)malloc(sizeof(char *) * size);
            int j = 0;
            while (size - 1 > j)
            {
                // printf("i: %d j: %d ", i, j);
                // printf("%s\n", check[i++]);
                info->map[j] = ft_strdup(check[i]);
                info->map_cp[j] = ft_strdup(check[i++]);
                // printf("%s\n", info->map[j]);
                j++;
            }
            // info->map[j] = ft_strdup('\0');
            // printf("\ntest:\n%s", info->map[j]);
            
            info->map_len = j;
            Free2DArray(check);
            return i;
        }
    }
    return (-1);
}


int	check_spawn(t_map *map)
{
    int i = -1;
    int j = -1;
    int character = 0;

    while (map->map_len > ++i)
    {
        if (ft_strchr(map->map[i], 'N') || ft_strchr(map->map[i], 'W')
            || ft_strchr(map->map[i], 'E') || ft_strchr(map->map[i], 'S'))
        {
            character++;
            map->px = i;
            while (map->map[i][++j])
            {
                if (map->map[i][j] == 'N' || map->map[i][j] == 'W'
                || map->map[i][j] == 'E' || map->map[i][j] == 'S')
                {
                    map->py = j;
                    map->pos = map->map[i][j];
                }
            
            }

        }
    }
    if (character == 1)
        return (0);
    return (1);
}


int check_row(char *str)
{
    int i = -1;
    int len = ft_strlen(str);
    
    // printf("test\n");
    // printf("%s\n", str);
    while (++i < len)
    {
        if (str[i] != ' ' && str[i] != '1')
            return (1);
    }
    return (0);
}

int check_row2(char *str)
{
    int i = 0;
    int len = ft_strlen(str);

    while (i < len)
    {
        // 공백이면 넘어감.
        // 공백이 아닌 경우 조건
        if (str[i] != ' ')
        {
            // 1아니라면 1을 반환.
            if (str[i] != '1')
            {
                printf("%s\n", str);
                return (1);
            }
            // 뒤는 검사할 필요 없음
            break;
        }
        i++;
    }
    // 마지막으로 왔을 때 1이 아니라면 에러
    if (str[len - 1] != '1')
    {
        printf("%s\n", str);
        return (1);
    }
    return (0);
}

int check_four_forward(t_map *info, int y, int x)
{
    // printf("y: %d, x: %d, map[y][x]: %c\n", y, x, info->map_cp[y][x]);
    // 마지막(인덱스의 범위가 0미만 혹은 width보다 큰 경우) 까지 간 경우 -> 1을 못찾아서 종료를 못함.
    if (y < 0 || x < 0 || y == info->height || x == info->width)
    {
        printf("test: ERROR four forward %c\n", info->map_cp[y][x]);
        return (1);
    }
    if (info->map_cp[y + 1][x] == ' ' || info->map_cp[y][x + 1] == ' '
        || info->map_cp[y - 1][x] == ' ' || info->map_cp[y][x - 1] == ' '
        || info->map_cp[y][x] == ' ')
        // 아래로 내려갈 때 공간이 안막혀 있는 에러는 처리가 아직 안됨...
        // || info->map_cp[y - 1][x] == 'N' || info->map_cp[y + 1][x] == 'N')
    {
        printf("test: ERROR four forward %c\n", info->map_cp[y][x]);
        return (1);
    }

    if (y == 5 && x == 31)
        printf("5, 31 : %c\n", info->map_cp[5][31]);

    info->map_cp[y][x] = '1';
    // printf("%c", info->map[y][x]);
    // 만약 다음것이 0이라면 재귀로 반복
    if (info->map_cp[y - 1][x] == '0')
        return (check_four_forward(info, y - 1, x));
    if (info->map_cp[y + 1][x] == '0')
        return (check_four_forward(info, y + 1, x));
    if (info->map_cp[y][x + 1] == '0')
        return (check_four_forward(info, y, x + 1));
    if (info->map_cp[y][x - 1] == '0')
        return (check_four_forward(info, y, x - 1));
    return (0);
}

int check_row3(t_map *map)
{
    // 세로 값
    int i = -1;
    // 가로 값
    int j;
    
    int height = map->height;
    int width;
    while (++i < height)
    {
        j = -1;
        width = ft_strlen(map->map[i]);
        // printf("%d\n", width);
        // printf("%s\n", map->map[i]);
        while (++j < width)
        {
            // printf("%c", map->map[i][j]);
            if (map->map[i][j] == '0')
            {
                // printf("hello\n");
                check_four_forward(map, i, j);
            }
        }
        // printf("\n");
    }
    return 0;
}
// 조건
// 1. 사방이 전부 1로 둘러싸여야한다.
// 2번 조건 다른 게 있을까? 없는 것 같은디...
// 주변이 1로 둘러쌓여 잇으면 되는 건데 그 왜 조건 있나?

int	check_map(t_map *info)
{
    int i = -1;
    // 간단하게 맨위랑 중간 부분의 양끝 부분 1로 둘러쌓여 있는지 확인
    while (++i < info->map_len)
    {
        if (i == 0 || i == info->map_len - 1)
        {
            if (check_row(info->map[i]))
            {
                printf("%s\n", info->map[i]);
                // ft_error("ERROR: map isn't surrounded wall\n");
                // printf("wrong map\n");
                return (1);
            }
            
        }
        else
        {
            if (check_row2(info->map[i]))
            {
                ft_error("ERROR: map isn't surrounded wall\n");
                return (1);
            }
        }
    }
    if (check_row3(info))
    {
        ft_error("ERROR: map isn't surrounded wall\n");
        return (1);   
    }
	return (0);
}

int	parsing_map(t_map *info, char *full_path)
{
	int		start_index;

    (void)info;

    // 0번부터 시작하는 인덱스이다.
    // 만약 처음 시작이 1이라면 start_index에 1을 더해주도록한다.
	start_index = find_map(full_path, info);
    if (start_index == -1)
		return (ft_error("Invalid map area"));
    // printf("\nstart index: %d\n", start_index);
    info->height = info->map_len;
    int i = 0;
    int width = 0;
    while (i < info->height)
    {
        width = ft_strlen(info->map[i]);
        if (width > info->width)
            info->width = width;
        i++;
    }
    // printf("map width : %d\n", info->width);
    // printf("map height: %d\n", info->height);

    if (check_spawn(info))
        return (ft_error("NSWE is not in the map\n"));
    if (check_map(info))
        return (ft_error("Map is not surrounded wall\n"));
	return (0);
}