/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:24:17 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/19 11:51:41 by minjinki         ###   ########.fr       */
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
int				read_till_end(int fd, char **line);
// static char	    *ft_join(char *s1, char *s2);
int				parsing_all(int fd, t_game *game_all, t_map *map_all);
int				init_input(t_game *game_all, char *map_path);
int				ft_parsing_master(char **argv, t_game *game_all);
int				ft_error(char *msg);

int				make_rgb(int r, int g, int b);
int				get_r(int rgb);
int				get_g(int rgb);
int				get_b(int rgb);

char			**Free2DArray(char **array);
int				ft_isdigitString(char *str);
int				check_rgb(char **split, t_color *color_s);
int				get_findex(char *str, char c);
char			*ft_strstr(const char *text, const char *pattern);
void			free_all(t_game *game);

int				parsing_map(t_map *info, char *full_path);
int				find_map(char *full_file, t_map *info);

int				init_game(t_game *game);

void			render_img(t_game *game);

int				key_press(int key, t_game *game);

int				end_game(t_game *game);

#endif