/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:51:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/17 22:34:22 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project(t_data *data, int x, int y, int z)
{
	double	px;
	double	py;
	double	pz;

	px = (x + data->shift_x) - (data->map_length - 1) / 2.0;
	py = (y + data->shift_y) - (data->map_height - 1) / 2.0;
	pz = z;
	if (data->proj_type == 0)
		return (iso_proj(px, py, pz, data));
	else
		return (top_proj(px, py, pz, data));
}

void	draw_line(t_data *data, t_point start, t_point end)
{
	t_point	tmp;
	int		nbr_of_steps;
	int		i;

	tmp = start;
	tmp.delta_x = end.x - start.x;
	tmp.delta_y = end.y - start.y;
	nbr_of_steps = fmax(fabs(tmp.delta_x), fabs(tmp.delta_y)) + 1;
	tmp.x_increment = tmp.delta_x / (double)nbr_of_steps;
	tmp.y_increment = tmp.delta_y / (double)nbr_of_steps;
	i = 0;
	while (i <= nbr_of_steps)
	{
		my_mlx_pixel_put(data, round(tmp.x), round(tmp.y), 0x00000FF);
		tmp.x += tmp.x_increment;
		tmp.y += tmp.y_increment;
		i++;
	}
}

void	draw_map(t_data *data)
{
	t_point	end;

	data->y = -1;
	while (++data->y < data->map_height)
	{
		data->x = -1;
		while (++data->x < data->map_length)
		{
			data->curr = project(data, data->x, data->y,
					data->matrix[data->y][data->x]);
			if (data->x < data->map_length - 1)
			{
				end = project(data, data->x + 1, data->y,
						data->matrix[data->y][data->x + 1]);
				draw_line(data, data->curr, end);
			}
			if (data->y < data->map_height - 1)
			{
				end = project(data, data->x, data->y + 1,
						data->matrix[data->y + 1][data->x]);
				draw_line(data, data->curr, end);
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
