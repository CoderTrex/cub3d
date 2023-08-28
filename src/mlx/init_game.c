/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:15:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/28 16:14:38 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_dir(t_game *game)
{
	if (game->map.pos == 'W')
	{
		game->xpm.dir_x = 0.0;
		game->xpm.dir_y = -1.0;
		game->xpm.plane_x = 0.66;
		game->xpm.plane_y = 0.0;
	}
	else if (game->map.pos == 'E')
	{
		game->xpm.dir_x = 0.0;
		game->xpm.dir_y = 1.0;
		game->xpm.plane_x = -0.66;
		game->xpm.plane_y = 0.0;
	}
	else if (game->map.pos == 'N')
	{
		game->xpm.dir_x = -1.0;
		game->xpm.dir_y = 0.0;
		game->xpm.plane_x = 0.0;
		game->xpm.plane_y = -0.66;
	}
	else if (game->map.pos == 'S')
	{
		game->xpm.dir_x = 1.0;
		game->xpm.dir_y = 0.0;
		game->xpm.plane_x = 0.0;
		game->xpm.plane_y = 0.66;
	}
}

int	init_data(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (ft_error("Fail to start game\n"));
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	game->xpm.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->xpm.addr = (int *)mlx_get_data_addr(game->xpm.img,
			&(game->xpm.bpp), &(game->xpm.len), &(game->xpm.endian));
	game->xpm.pos_x = (double)game->map.px + 0.5;
	game->xpm.pos_y = (double)game->map.py + 0.5;
	set_dir(game);
	game->xpm.forward = 0;
	game->xpm.backward = 0;
	game->xpm.left = 0;
	game->xpm.right = 0;
	game->xpm.rrot = 0;
	game->xpm.lrot = 0;
	game->xpm.move_sp = 0.51;
	game->xpm.rot_sp = 0.1;
	game->map.map[game->map.px][game->map.py] = '0';
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

int	init_texture(t_game *game, t_tex *tex, int i)
{
	char	*path;

	path = NULL;
	if (i == NORTH)
		path = game->img.north;
	else if (i == SOUTH)
		path = game->img.south;
	else if (i == WEST)
		path = game->img.west;
	else if (i == EAST)
		path = game->img.east;
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &(tex->width),
			&(tex->height));
	if (!(tex->img))
		return (ft_error("Fail to load texture\n"));
	tex->addr = mlx_get_data_addr(tex->img, &(tex->bpp), &(tex->len),
			&(tex->endian));
	return (0);
}

int	init_game(t_game *game)
{
	int		i;
	t_xpm	xpm;

	ft_bzero(&xpm, sizeof(xpm));
	game->xpm = xpm;
	if (init_data(game))
		return (1);
	i = -1;
	while (++i < 4)
		if (init_texture(game, &(game->xpm.tex[i]), i))
			return (1);
	render_img(game);
	print_img(game);
	mlx_loop_hook(game->mlx, move, game);
	mlx_hook(game->win, KEY_EXIT, 0, end_game, game);
	mlx_hook(game->win, KEY_PRESS, 0, key_press, game);
	mlx_hook(game->win, KEY_RELEASE, 0, key_release, game);
	mlx_loop(game->mlx);
	ft_error("Fail to start game\n");
	return (0);
}
