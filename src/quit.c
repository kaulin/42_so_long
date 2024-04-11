/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:41:13 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/11 10:21:14 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Quits with a provided error message.
*/
void	quit_error(char *error_message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

/*
Quits with a provided error message using perror.
*/
void	quit_perror(char *error_message)
{
	ft_putstr_fd("Error\n", 2);
	perror(error_message);
	exit(EXIT_FAILURE);
}

/*
Cleans all allocated memory and quits with provided error message.
*/
void	quit_data_error(t_data *data, char *error_message)
{
	clean_data(data);
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

/*
Cleans all allocated memory and quits with provided error message using perror.
*/
void	quit_data_perror(t_data *data, char *error_message)
{
	clean_data(data);
	ft_putstr_fd("Error\n", 2);
	perror(error_message);
	exit(EXIT_FAILURE);
}


/*
Cleans all allocated memory and quits with provided message and EXIT_SUCCESS.
*/
void	quit_success(t_data *data, char *message)
{
	clean_data(data);
	if (message)
		ft_putendl_fd(message, 1);
	exit(EXIT_SUCCESS);
}
