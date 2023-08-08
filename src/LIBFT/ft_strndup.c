/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:28:51 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/18 13:09:13 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*res;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
