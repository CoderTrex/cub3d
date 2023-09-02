/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:52:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/02 12:45:40 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_strcpy_with_space(char *dst, const char *src)
{
	int	i;
	int	j;

	if (!src)
		return ;
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == '\n')
			dst[j++] = ' ';
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
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
