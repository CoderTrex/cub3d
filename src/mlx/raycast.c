/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:19:17 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/29 11:13:51 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	cal_dda(t_game *game)
{
	while (game->xpm.hit == 0)
	{
		if (game->xpm.sidedist_x < game->xpm.sidedist_y)
		{
			game->xpm.sidedist_x += game->xpm.deltadist_x;
			game->xpm.map_x += game->xpm.step_x;
			game->xpm.side = 0;
		}
		else
		{
			game->xpm.sidedist_y += game->xpm.deltadist_y;
			game->xpm.map_y += game->xpm.step_y;
			game->xpm.side = 1;
		}
		if (game->map.map[game->xpm.map_x][game->xpm.map_y] == '1')
			game->xpm.hit = 1;
	}
}

int	find_tex_idx(t_xpm *xpm)
{
	if (xpm->side == 0)
	{
		if (xpm->raydir_x < 0)
			return (NORTH);
		else
			return (SOUTH);
	}
	else
	{
		if (xpm->raydir_y < 0)
			return (WEST);
		else
			return (EAST);
	}
}

int	draw(t_game *game, t_xpm *xpm, t_tex *tex, int i)
{
	int				y;
	char			*dst;
	double			pos;
	unsigned int	color;

	y = xpm->start;
	pos = (xpm->start - HEIGHT / 2 + xpm->height / 2) * xpm->tex_y_step;
	while (y <= xpm->end)
	{
		xpm->tex_y = (int)pos & (tex->height - 1);
		pos += xpm->tex_y_step;
		dst = tex->addr
			+ (int)(xpm->tex_y * tex->len + xpm->tex_x * (tex->bpp / 8));
		color = *(unsigned int *)dst;
		put_pixel(game, WIDTH - i, y, color);
		xpm->tex_y += xpm->tex_y_step;
		y++;
	}
	return (0);
}

int	set_screen(t_game *game, t_xpm *xpm, t_tex *tex, int i)
{
	if (xpm->side == 0)
		xpm->wall = xpm->pos_y + xpm->perpwalldist * xpm->raydir_y;
	else
		xpm->wall = xpm->pos_x + xpm->perpwalldist * xpm->raydir_x;
	xpm->wall -= floor(xpm->wall);
	xpm->tex_x = (int)(xpm->wall * (double)IMG_W);
	if (xpm->side == 0 && xpm->raydir_x > 0)
		xpm->tex_x = IMG_W - xpm->tex_x - 1;
	if (xpm->side == 1 && xpm->raydir_y < 0)
		xpm->tex_x = IMG_W - xpm->tex_x - 1;
	xpm->tex_y = 0;
	xpm->tex_y_step = IMG_H / (double)xpm->height;
	if (xpm->height > HEIGHT)
		xpm->tex_y = (xpm->height - HEIGHT) / 2 * xpm->tex_y_step;
	draw(game, xpm, tex, i);
	return (0);
}

void	draw_texture(t_game *game, int i)
{
	int	num;

	num = find_tex_idx(&(game->xpm));
	set_screen(game, &(game->xpm), &(game->xpm.tex[num]), i);
}
