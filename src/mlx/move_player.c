/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:24:32 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/27 11:39:08 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	move_player(t_game *game, double x, double y)
{
	int	next_x;
	int	next_y;

	next_x = (int)(game->xpm.pos_x + x * game->xpm.move_sp);
	next_y = (int)(game->xpm.pos_y + y * game->xpm.move_sp);
	if (game->map.map[next_x][(int)(game->xpm.pos_y)] == '0')
	{
		game->xpm.pos_x += x * game->xpm.move_sp;	// (game->xpm.move_sp - 0.01?);
		render_img(game);
		print_img(game);
	}
	if (game->map.map[(int)(game->xpm.pos_x)][next_y] == '0')
	{
		game->xpm.pos_y += y * game->xpm.move_sp;	// (game->xpm.move_sp - 0.01?);
		render_img(game);
		print_img(game);
	}
	return (1);
}

int	rotate_player(t_game *game, double rot_sp)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->xpm.dir_x;
	game->xpm.dir_x = game->xpm.dir_x * cos(rot_sp)
		- game->xpm.dir_y * sin(rot_sp);
	game->xpm.dir_y = olddir_x * sin(rot_sp) + game->xpm.dir_y * cos(rot_sp);
	oldplane_x = game->xpm.plane_x;
	game->xpm.plane_x = game->xpm.plane_x * cos(rot_sp)
		- game->xpm.plane_y * sin(rot_sp);
	game->xpm.plane_y = oldplane_x * sin(rot_sp)
		+ game->xpm.plane_y * cos(rot_sp);
	render_img(game);
	print_img(game);
	return (0);
}

int	move(t_game *game)
{
	if (game->xpm.forward == 1)
		move_player(game, game->xpm.dir_x, game->xpm.dir_y);
	if (game->xpm.backward == 1)
		move_player(game, -game->xpm.dir_x, -game->xpm.dir_y);
	if (game->xpm.left == 1)
		move_player(game, -game->xpm.plane_x, game->xpm.plane_y);
	if (game->xpm.right == 1)
		move_player(game, game->xpm.plane_x, -game->xpm.plane_y);
	if (game->xpm.lrot == 1)
		rotate_player(game, -game->xpm.rot_sp);
	if (game->xpm.rrot == 1)
		rotate_player(game, game->xpm.rot_sp);
	return (1);
}
