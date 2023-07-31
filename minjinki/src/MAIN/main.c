/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:23:40 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/18 16:35:27 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_av(char **av)
{
	if ((ft_strlen(av[1]) > 4
			&& ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub") != 0)
		|| ft_strlen(argv[1]) <= 4)
		exit_with_code(1, "Check if the extension of file is .cub file\n");
}

void	init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_with_code(1, "No such file\n");
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		exit_with_code(1, "Fail to allocate memory\n"
	read_file(fd, game);
	if (!game->map->map[0])
		exit_with_code(1, "Empty map file\n");
	close(fd);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (print_error("Usage: ./cub3d file.cub [--save]\n"));
	check_av(av);
	init(&game);
}
