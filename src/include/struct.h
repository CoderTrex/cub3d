/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:20:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/18 18:51:50 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	int		floor;
	int		ceil;

	void	*north;
	void	*south;
	void	*west;
	void	*east;
	void	*tmp;
}	t_img;

typedef struct s_map
{
	char 	*full_path;
	char	**map;
	int		map_len;
	int		width;
	int		height;

	unsigned int floor_color;
	unsigned int cell_color;
	
	unsigned int px;
	unsigned int py;
}	t_map;

typedef struct s_color
{
	int R;
	int G;
	int B;
} t_color;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	t_img	img;
	t_map	map;
}	t_game;

#endif