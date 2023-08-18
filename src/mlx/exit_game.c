/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:18:42 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/18 17:43:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->xpm.north);
	mlx_destroy_image(game->mlx, game->xpm.south);
	mlx_destroy_image(game->mlx, game->xpm.west);
	mlx_destroy_image(game->mlx, game->xpm.east);
}

void	end_game(t_game *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->win);
	free_all(game);
}
