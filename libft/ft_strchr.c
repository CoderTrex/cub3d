/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:48:54 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/18 13:08:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*(unsigned char *)s != (unsigned char)c)
	{
		if (*(unsigned char *)s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
