/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:48:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/25 13:50:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned int	get_color(t_game *game, t_tex *tex, int tex_y)
{
	char	*color;

	color = tex->addr + (tex_y * tex->len + game->xpm.tex_x * (tex->bpp / 8));
	return (*(unsigned int *)color);
}

void	put_pixel(t_game *game, int x, int y, unsigned int color)
{
	char	*dst;

	dst = game->xpm.addr + (y * game->xpm.len + x * (game->xpm.bpp / 8));
	*(unsigned int *)dst = color;
}

int	print_img(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->xpm.img, 0, 0);
	return (0);
}
