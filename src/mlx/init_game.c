/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:15:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/18 17:00:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_data(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (ft_error("Fail to start game\n"));
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	return (0);
}

void	init_img(t_xpm *xpm, t_game *game)
{
	int	img_w;
	int	img_h;

	xpm->north = mlx_xpm_file_to_image(game->mlx, game->img.north,
			&img_w, &img_h);
	xpm->south = mlx_xpm_file_to_image(game->mlx, game->img.south,
			&img_w, &img_h);
	xpm->west = mlx_xpm_file_to_image(game->mlx, game->img.west,
			&img_w, &img_h);
	xpm->east = mlx_xpm_file_to_image(game->mlx, game->img.east,
			&img_w, &img_h);
}

int	init_game(t_game *game)
{
	t_xpm	xpm;

	ft_bzero(&xpm, sizeof(xpm));
	if (init_data(game))
		return (1);
	game->xpm = xpm;
	init_img(&(game->xpm), game);
	return (0);
}
