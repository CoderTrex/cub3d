/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:24:17 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/02 12:46:56 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 42

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# include "libft.h"
# include "struct.h"
# include "../mlx/mlx.h"

void			ft_strcpy(char *dst, const char *src);
int				check_buff_end(int fd, char **line, char **line_space);
int				parsing_all(int fd, t_game *game_all, t_map *map_all);
int				init_input(t_game *game_all, char *map_path);
int				ft_parsing_master(char **argv, t_game *game_all);
int				ft_error(char *msg);

int				make_rgb(int r, int g, int b);
int				get_r(int rgb);
int				get_g(int rgb);
int				get_b(int rgb);

char			**free_2d_array(char **array);
int				ft_isdigit_string(char *str);
int				check_rgb(char **split, t_color *color_s);
int				get_findex(char *str, char c);
char			*ft_strstr(const char *text, const char *pattern);
char			*create_line(char *str, char *needle);
char			*remove_spaces(char *input);
void			free_all(t_game *game);

int				find_map_setting2(char *check, int i);
int				find_map_setting3(char *check, int i);
int				find_map_setting(t_map *info, char **check, int size);

int				parsing_map(t_map *info, char *full_path);
int				find_map(char *full_file, t_map *info);
void			remake_map(t_map *map);
int				check_spawn(t_map *map);
int				check_row(char *str);
int				check_row2(char *str);
int				check_row3(t_map *map);
char			**copy_array(char **src, int rows, int cols);
int				init_game(t_game *game);
void			set_dir(t_game *game);

void			draw_texture(t_game *game, int i);
void			cal_dda(t_game *game);
void			get_hit_pos(t_game *game);
void			put_pixel(t_game *game, int x, int y, unsigned int color);
unsigned int	get_color(t_game *game, t_tex *tex, int tex_y);

int				print_img(t_game *game);
void			render_img(t_game *game);

int				key_press(int key, t_game *game);
int				key_release(int key, t_game *game);

int				move(t_game *game);
void			print_map_with_player(t_game *game);

int				end_game(t_game *game);

void			ft_strcpy_with_space(char *dst, const char *src);
int				find_map_setting4(t_map *info, char **check);
void			remake_map2(t_map *map, int height);
int				check_four_forward2(t_map *info, int y, int x, int h);
int				ft_strange_map_check(t_map *info, char *map);

#endif