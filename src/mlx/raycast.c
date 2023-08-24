/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:19:17 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/24 17:13:38 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	cal_dda(t_game *game)
{
	while (game->xpm.hit == 0)
	{
		if (game->xpm.sidedist_x < game->xpm.sidedist_y)
		{
			game->xpm.sidedist_x += game->xpm.deltadist_y;
			game->xpm.map_x += game->xpm.step_x;
			game->xpm.side = 0;
		}
		else
		{
			game->xpm.sidedist_y += game->xpm.deltadist_x;
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
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (xpm->raydir_y < 0)
			return (NORTH);
		else
			return (SOUTH);
	}
}

void	get_hit_pos(t_game *game)
{
	if (game->xpm.side == 0)
		game->xpm.perpwalldist = (game->xpm.map_x - game->xpm.pos_x
				+ (1 - game->xpm.step_x) / 2) / game->xpm.raydir_x;
	else
		game->xpm.perpwalldist = (game->xpm.map_y - game->xpm.pos_y
				+ (1 - game->xpm.step_y) / 2) / game->xpm.raydir_y;
	game->xpm.height = (int)(HEIGHT / game->xpm.perpwalldist);
	game->xpm.start = HEIGHT / 2 - game->xpm.height / 2;
	if (game->xpm.start < 0)
		game->xpm.start = 0;
	game->xpm.end = game->xpm.height / 2 + HEIGHT / 2;
	if (game->xpm.end >= HEIGHT)
		game->xpm.end = HEIGHT - 1;
}

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

void	set_texture(t_game *game, int x, int num)
{
	int				i;
	int				tex_y;
	double			step;
	double			tex_pos;
	unsigned int	color;

	step = 1.0 * IMG_H / game->xpm.height;
	tex_pos = (game->xpm.start - HEIGHT / 2 + game->xpm.height / 2) * step;
	i = game->xpm.start;
	while (i < game->xpm.end)
	{
		tex_y = (int)tex_pos & (IMG_H - 1);
		tex_pos += step;
		color = get_color(game, game->xpm.tex[num], tex_y);
		put_pixel(game, x, i, color);
		i++;
	}
}

void	draw_texture(t_game *game, int i, int map_y, void *texture)
{
	int	num;

	num = find_tex_idx(game->xpm);
	get_hit_pos(game);
	set_texture(game, i, num);
}
