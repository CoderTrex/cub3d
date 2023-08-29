/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:18:42 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/29 15:49:51 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	leak(void)
{
	system("leaks cub3d");
}

void	free_all(t_game *game)
{
	free(game->img.east);
	free(game->img.north);
	free(game->img.south);
	free(game->img.west);
}

void	destroy_img(t_game *game)
{
	if (game->xpm.north)
		mlx_destroy_image(game->mlx, game->xpm.north);
	if (game->xpm.south)
		mlx_destroy_image(game->mlx, game->xpm.south);
	if (game->xpm.west)
		mlx_destroy_image(game->mlx, game->xpm.west);
	if (game->xpm.east)
		mlx_destroy_image(game->mlx, game->xpm.east);
}

int	end_game(t_game *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->win);
	free_all(game);
	printf("--------------------------------\n     THANK YOU FOR PLAYING!\n");
	printf("--------------------------------\n");
	atexit(leak);
	exit(0);
}
