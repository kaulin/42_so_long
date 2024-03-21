/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:56:21 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/21 10:52:12 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_map
{
	char	*map_str;
	char	**map;
	size_t	rows;
	size_t	cols;
	size_t	objs;
	size_t	start_x;
	size_t	start_y;
	size_t	exit_x;
	size_t	exit_y;
	size_t	**visited;
}	t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*obj;
	mlx_image_t	*exit;
	mlx_image_t	*background;
	size_t		height;
	size_t		width;
	size_t		pos_x;
	size_t		pos_y;
	size_t		moves;
}	t_data;

void	check_map(char *map_file, t_map *map);
void	clean_map(t_map *map);
void	clean_data(t_data *data);
void	quit_file_error(char *error_message);
void	quit_map_error(t_map *map, char *error_message);
void	quit_error(t_data *data, char *error_message);
void	quit_success(t_data *data, char *message);

#endif