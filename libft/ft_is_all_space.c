/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:38:49 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/02 12:39:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_is_all_space(char *s)
{
	int	i;

	i = -1;
	if (!ft_is_space(s[++i]))
		return (FALSE);
	return (TRUE);
}

