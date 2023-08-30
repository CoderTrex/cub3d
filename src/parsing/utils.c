/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:59:41 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/30 11:43:44 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**free_2d_array(char **array)
{
	int	count;

	count = 0;
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

int	ft_isdigit_string(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
		{
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
	int	number;

	i = 0;
	if (!split || !split[0] || !split[1] || !split[2])
		return (ft_error("RGB is not correct Value1\n"));
	while (split[i])
	{
		if (ft_isdigit_string(split[i]))
		{
			return (ft_error("RGB is not correct Value2\n"));
		}
		number = ft_atoi(split[i]);
		if (number > 255 || number < 0)
			return (ft_error("RGB values must be within 0 and 255"));
		if (i == 0)
			color_s->r = number;
		if (i == 1)
			color_s->g = number;
		if (i == 2)
			color_s->b = number;
		i++;
	}
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
	const char	*hay;
	const char	*ndl;

	if (*pattern == '\0')
		return ((char *)text);
	while (*text)
	{
		hay = text;
		ndl = pattern;
		while (*hay && *ndl && *hay == *ndl)
		{
			hay++;
			ndl++;
		}
		if (*ndl == '\0')
			return ((char *)text);
		text++;
	}
	return (NULL);
}
