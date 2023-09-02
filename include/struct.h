/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:20:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/02 12:44:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 1280
# define HEIGHT 960
# define IMG_W 64
# define IMG_H 64

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# define PURPLE "\033[0;35m"
# define RESET "\033[0m"

typedef struct s_tex
{
	void	*img;
	void	*addr;
	int		bpp;
	int		endian;
	int		len;
	int		width;
	int		height;
}	t_tex;

typedef struct s_xpm
{
	t_tex	tex[4];

	void	*img;
	void	*addr;
	int		bpp;
	int		endian;
	int		len;
	int		img_w;
	int		img_h;

	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_sp;
	double	rot_sp;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		height;
	int		start;
	int		end;
	double	wall;
	int		tex_x;
	double	tex_y;
	double	tex_y_step;

	int		hit;
	int		side;
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		rrot;
	int		lrot;
}	t_xpm;

typedef struct s_img
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	void	*tmp;
}	t_img;

typedef struct s_map
{
	char			*full_path;
	char			*full_path_space;
	char			**map;

	char			**map_cp;
	char			**map_cp2;
	char			**map_cp3;
	char			**map_cp4;

	int				map_len;
	int				width;
	int				height;
	int				start;

	unsigned int	floor_color;
	unsigned int	cell_color;

	unsigned int	px;
	unsigned int	py;
	char			pos;
}	t_map;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	t_img	img;
	t_map	map;
	t_xpm	xpm;
}	t_game;

#endif