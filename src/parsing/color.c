/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:28:55 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/29 14:29:41 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	make_rgb(int r, int g, int b)
{
	return (0xFFFFFF & (r << 16 | g << 8 | b));
}

int	get_r(int rgb)
{
	rgb = rgb & 0x00ff0000;
	rgb = rgb >> 16;
	return (rgb);
}

int	get_g(int rgb)
{
	rgb = rgb & 0x0000ff00;
	rgb = rgb >> 8;
	return (rgb);
}

int	get_b(int rgb)
{
	rgb = rgb & 0x000000ff;
	rgb = rgb >> 0;
	return (rgb);
}
