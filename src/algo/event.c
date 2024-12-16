/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:11:35 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/16 22:23:48 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->map_height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

void	free_data(t_data *data)
{
	free_matrix(data);
	free(data);
}

void	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_data(data);
}

int	handle_press(int key, t_data *data)
{
	if (key == ESCAPE)
		handle_close(data);
	return (0);
}

void	handle_event(t_data *data)
{
	mlx_hook(data->window, KeyPress, KeyPressMask, handle_press, data);
}