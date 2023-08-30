/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:53:57 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/28 10:54:31 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		end_game(game);
	else if (key == W)
		game->xpm.forward = 1;
	else if (key == S)
		game->xpm.backward = 1;
	else if (key == A)
		game->xpm.left = 1;
	else if (key == D)
		game->xpm.right = 1;
	else if (key == LEFT)
		game->xpm.lrot = 1;
	else if (key == RIGHT)
		game->xpm.rrot = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == W)
		game->xpm.forward = 0;
	else if (key == S)
		game->xpm.backward = 0;
	else if (key == A)
		game->xpm.left = 0;
	else if (key == D)
		game->xpm.right = 0;
	else if (key == LEFT)
		game->xpm.lrot = 0;
	else if (key == RIGHT)
		game->xpm.rrot = 0;
	return (0);
}
