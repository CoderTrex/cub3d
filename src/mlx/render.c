/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:52:58 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/23 12:23:57 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	paint(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < HEIGHT / 2)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			mlx_pixel_put(game->mlx, game->win, x, y, game->map.cell_color);
// 			mlx_pixel_put(game->mlx, game->win, x, HEIGHT - y - 1, game->map.floor_color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	paint_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			game->buf[y][x] = game->map.cell_color;
			game->buf[HEIGHT - y - 1][x] = game->map.floor_color;
			x++;
		}
		y++;
	}
}

void	ray_casting(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(game, x);
		calculate();
		fill_buf();
		x++;
	}
}

int	render_img(t_game *game)
{
	//paint(game);	// test
	paint_floor_ceiling(game);
	ray_casting(game);
	//paint(game); // ray_casting에서 buf에 저장한 내용을 기반으로 pixel_put
	mlx_hook(game->win, KEY_EXIT, 0, end_game, game);
	mlx_hook(game->win, KEY_PRESS, 0, key_press, game);
	mlx_hook(game->win, KEY_RELEASE, 0, key_release, game);
	return (0);
}
