/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:15:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/02 11:48:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	game->xpm.move_sp = 0.3;
	game->xpm.rot_sp = 0.1;
	game->map.map[game->map.px][game->map.py] = '0';
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
