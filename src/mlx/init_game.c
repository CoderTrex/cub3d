/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:15:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/20 12:25:12 by minjinki         ###   ########.fr       */
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

int	init_img(t_xpm *xpm, t_game *game)
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
	if (!(xpm->north) || !(xpm->south) || !(xpm->west) || !(xpm->east))
		return (ft_error("Fail to load texture\n"));
	return (0);
}

int	init_game(t_game *game)
{
	t_xpm	xpm;

	ft_bzero(&xpm, sizeof(xpm));
	if (init_data(game))
		return (1);
	game->xpm = xpm;
	if (init_img(&(game->xpm), game))
		return (1);
	// render_img(game);
	game->xpm.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->xpm.addr = (int *)mlx_get_data_addr(game->xpm.img,
			&(game->xpm.bpp), &(game->xpm.size_l), &(game->xpm.endian));
	mlx_loop_hook(game->mlx, render_img, game);
	mlx_loop(game->mlx);
	ft_error("Fail to start game\n");
	return (0);
}
