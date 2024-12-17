/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:11:35 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/17 22:01:40 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_mouse(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (key == MOUSE_UP)
		data->zoom = data->zoom * 1.1;
	else if (key == MOUSE_DOWN)
		data->zoom = data->zoom * 0.9;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
						&data->line_length, &data->endian);
	draw_map(data);
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_data(data);
	exit(1);
}

int	wich_key(int key, t_data *data)
{
	if (key == ESCAPE)
		handle_close(data);
	if (key == KEY_DOWN)
		data->coef--;
	if (key == KEY_UP)
		data->coef++;
	if (key == W_KEY)
		data->shift_y--;
	if (key == S_KEY)
		data->shift_y++;
	if (key == A_KEY)
		data->shift_x--;
	if (key == D_KEY)
		data->shift_x++;
	return (0);
}

int	handle_press(int key, t_data *data)
{
	wich_key(key, data);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
							&data->line_length, &data->endian);
	draw_map(data);
	return (0);
}

void	handle_event(t_data *data)
{
	mlx_mouse_hook(data->window, handle_mouse, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, handle_press, data);
	mlx_hook(data->window, 17, 0, handle_close, data);
}
