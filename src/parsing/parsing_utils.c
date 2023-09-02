/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:52:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/29 15:18:29 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_strcpy(char *dst, const char *src)
{
	int	i;

	if (!src)
		return ;
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static char	*ft_join(char *s1, char *s2)
{
	int		line_len;
	char	*joined;

	if (!s2)
		return (s1);
	if (s1)
		line_len = ft_strlen(s1);
	else
		line_len = 0;
	joined = malloc(ft_strlen(s2) + line_len + 1);
	if (!joined)
		return (NULL);
	ft_strcpy(joined, s1);
	ft_strcpy(joined + line_len, s2);
	free(s1);
	return (joined);
}

int	check_buff_end(int fd, char **line)
{
	int			ret;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = 0;
	ret = 1;
	while (ret > 0)
	{
		*line = ft_join(*line, buf);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
	}
	return (0);
}

char	*create_line(char *str, char *needle)
{
	char	*line;
	char	*trimmedline;
	int		index;

	line = ft_strstr(str, needle);
	if (line)
	{
		line += ft_strlen(needle);
		while (*line == ' ')
			line++;
		index = get_findex(line, '\n');
		line = ft_substr(line, 0, index);
		trimmedline = ft_strtrim(line, " ");
		free(line);
		return (trimmedline);
	}
	return (NULL);
}

char	*remove_spaces(char *input)
{
	int		i;
	int		j;
	char	*output;

	i = -1;
	j = 0;
	while (input[++i])
	{
		if (input[i] != ' ' && input[i] > 0)
			j++;
	}
	output = malloc(sizeof(char *) * j);
	i = -1;
	j = 0;
	while (input[++i])
	{
		if (input[i] != ' ' && input[i] > 0)
		{
			output[j] = input[i];
			j++;
		}
	}
	output[j] = '\0';
	return (output);
}
