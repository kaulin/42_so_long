/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:56:21 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/10 12:58:34 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_data
{
	int			fd;
	char		**map;
	int			rows;
	int			cols;
	int			tokens;
	char		**visited;
	t_point		start_point;
	t_point		exit_point;
	mlx_t		*mlx;
	mlx_image_t	*img_player;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_token;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_empty;
	int			tile_size;
	int			height;
	int			width;
	int			x;
	int			y;
	int			moves;
}	t_data;

mlx_image_t	*convert_png(t_data *data, char *file);
int			check_mapfile(t_data *data, char *mapfile);
void		check_cols(t_data *data);
void		check_walls(t_data *data);
void		check_chars(t_data *data);
void		check_access(t_data *data);
int			is_directory(char *filepath);
int			is_solvable(t_data *data, t_point point, int *v_col, int *v_exit);
void		count_chars(t_data *data, int *p, int *e, int *c);
void		init_data(char *mapfile, t_data *data);
void		escape_hook(void *param);
void		quit_hook(void *param);
void		move_to(t_data *data, int x, int y);
void		move_keyhook(mlx_key_data_t keydata, void* param);
void		clean_mlx(t_data *data);
void		clean_data(t_data *data);
void		quit_error(char *error_message);
void		quit_perror(char *error_message);
void		quit_data_error(t_data *data, char *error_message);
void		quit_data_perror(t_data *data, char *error_message);
void		quit_success(t_data *data, char *message);
t_point 	set_point(int x, int y);
void		print_map(t_data *data);
void		print_floodfill(t_data *data);
#endif