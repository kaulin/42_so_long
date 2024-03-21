/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:41:13 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/20 17:02:23 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit_file_error(char *error_message)
{
	ft_putstr_fd("Error\n", 2);
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	quit_map_error(t_map *map, char *error_message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(error_message, 2);
	clean_map(map);
	exit(EXIT_FAILURE);
}

void	quit_error(t_data *data, char *error_message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(error_message, 2);
	clean_data(data);
	exit(EXIT_FAILURE);
}

void	quit_success(t_data *data, char *message)
{
	if (message)
		ft_putendl_fd(message, 1);
	clean_data(data);
	exit(EXIT_SUCCESS);
}