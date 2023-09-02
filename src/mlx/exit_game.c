/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:18:42 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/30 11:45:12 by minjinki         ###   ########.fr       */
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
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(game->mlx, game->xpm.tex[i].img);
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
