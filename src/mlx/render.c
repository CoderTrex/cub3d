/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:52:58 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/20 15:03:06 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	paint(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, game->map.cell_color);
			mlx_pixel_put(game->mlx, game->win, x, HEIGHT - y - 1, game->map.floor_color);
			x++;
		}
		y++;
	}
}

void	ray_casting(t_game *game)
{
	//floor casting
	//wall casting
}

int	render_img(t_game *game)
{
	paint(game);	// test
	//ray_casting(game);
	//paint(game); // ray_casting에서 buf에 저장한 내용을 기반으로 pixel_put
	mlx_hook(game->win, 17, 0, end_game, game);
	mlx_hook(game->win, 2, 0, key_press, game);
	return (0);
}
