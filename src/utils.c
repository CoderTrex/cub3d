#include "./include/cub3d.h"

char	**Free2DArray(char **array)
{
	int count = 0;

	if (array)
	{
		while (array[count])
		{
			free(array[count]);
			count++;
		}
		free(array);
	}
	return (NULL);
}

int	ft_isdigitString(char *str)
{
    int i = 0;
    while (str && str[i])
    {
        // if (str[i] > '9' || '0' < str[i])
        // {
        //     // 엥 여기서 왜 0이 걸리지?
        //     printf("\nERROR Not digital is detect: %s, %c\n", str, str[i]);
        //     return (1);
        // }

        if (!ft_isdigit(str[i]))
        {
            // 엥 여기서 왜 0이 걸리지?
            printf("\nERROR Not digital is detect: %s\n", str);
            return (1);
        }
        i++;
    }
    return (0);
}

int	check_rgb(char **split, t_color *color_s)
{
	int	i;
    int number;
	i = 0;
	if (!split || !split[0] || !split[1] || !split[2])
		return (ft_error("RGB is not correct Value1\n"));
    
    while (split[i])
	{
        // printf("\nsplit test: %s", split[i]);
        if (ft_isdigitString(split[i]))
        {
            return (ft_error("RGB is not correct Value2\n"));
        }
        number = ft_atoi(split[i]);
        if (number > 255 || number < 0)
            return (ft_error("RGB values must be within 0 and 255"));
        if (i == 0)
            color_s->R = number;
        if (i == 1)
            color_s->G = number;
        if (i == 2)
            color_s->B = number;
        i++;
	}
    // printf("\n\nWhat is RGB: %d, %d, %d\n", color_s->R, color_s->G, color_s->B);
	return (0);
}

int	get_findex(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (-1);
}

char	*ft_strstr(const char *text, const char *pattern)
{
    if (*pattern == '\0')
        return (char *)text;
    while (*text)
    {
        const char *hay = text;
        const char *ndl = pattern;
        while (*hay && *ndl && *hay == *ndl)
        {
            hay++;
            ndl++;
        }
        if (*ndl == '\0')
            return (char *)text;
        text++;
    }
    return NULL;
}
