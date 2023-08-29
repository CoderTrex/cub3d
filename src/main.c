/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:26:16 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/29 14:27:35 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_error(char *msg)
{
	printf("%s", msg);
	return (1);
}

void	leak_check(void)
{
	system("leaks cub3d");
}

int	check_map_format(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len < 5 || argv[len - 1] != 'b'
		|| argv[len - 2] != 'u' || argv[len - 3] != 'c'
		|| argv[len - 4] != '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game_all;

	ft_bzero(&game_all, sizeof(game_all));
	if (argc != 2)
		return (ft_error("argc is must be 2\n"));
	if (check_map_format(argv[1]))
		return (ft_error("map format is wrong\n"));
	if (ft_parsing_master(argv, &game_all))
		return (1);
	if (init_game(&game_all))
		end_game(&game_all);
	atexit(leak_check);
	return (0);
}
