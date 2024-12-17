/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:22:31 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/17 18:40:16 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= LENGTH || y < 0 || y >= HEIGHT)
		return ;
	if ((y * data->line_length + x * (data->bits_per_pixel / 8)) >= (HEIGHT * data->line_length))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (perror("MLX initialization failed"), 1);
	data->window = mlx_new_window(data->mlx, 1920, 1080, "FdF");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
							&data->line_length, &data->endian);
	draw_map(data);
	handle_event(data);
	mlx_loop(data->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

 	if (argc != 2)
	{
		write(2, "Usage: ./fdf <map_file>\n", 24);
		return (1);
	}
	if (check_file_name(argv[1]) == 1)
		return (1);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (perror("Allocation error for data"), 1);
	init_matrix(argv[1], data);
	data->x = 0;
	data->y = 0;
	data->shift_x = 1;
	data->shift_y = 1;
	data->zoom = 20;
	data->coef = 1;
	init_data(data);
	return (0);
}
