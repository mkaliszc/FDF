/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:22:31 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/12 18:14:24 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_map(t_data *data)
{
	int x, y;
	int scale = 20;
	int offset_x = data->map_length / 2;
	int offset_y = data->map_height / 2;

	for (y = 0; y < data->map_height; y++)
	{
		for (x = 0; x < data->map_length - 1; x++)
		{
			int x0 = offset_x + x * scale;
			int y0 = offset_y + y * scale + data->matrix[y][x];
			int x1 = offset_x + (x + 1) * scale;
			int y1 = offset_y + y * scale + data->matrix[y][x + 1];
			draw_line(data, x0, y0, x1, y1, 0x00FFFFFF);
		}
	}
	for (x = 0; x < data->map_length; x++)
	{
		for (y = 0; y < data->map_height - 1; y++)
		{
			int x0 = offset_x + x * scale;
			int y0 = offset_y + y * scale + data->matrix[y][x];
			int x1 = offset_x + x * scale;
			int y1 = offset_y + (y + 1) * scale + data->matrix[y + 1][x];

			draw_line(data, x0, y0, x1, y1, 0x00FFFFFF);
		}
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->map_length || y < 0 || y >= data->map_height)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_data	*data;

/* 	if (argc != 2)
	{
		write(2, "Usage: ./fdf <map_file>\n", 24);
		return (1);
	}
	if (check_file_name(argv[1]) == 1)
		return (1); */
	(void)argc;
	(void)argv;
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (perror("Allocation error for data"), 1);
	//init_matrix(argv[1], data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (perror("MLX initialization failed"), 1);
	data->bits_per_pixel = 32;
    data->line_length = 1920 * (data->bits_per_pixel / 8);
    data->endian = 0;
	data->map_height = 1080;
	data->map_length = 1920;
	data->window = mlx_new_window(data->mlx, 1920, 1080, "FDF");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, 
								   &data->line_length, &data->endian);
	//draw_map(data);
	draw_line(data, 500, 500, 1500, 100, 0x00000FF); // tests
	draw_line(data, 100, 100, 300, 300, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	mlx_loop(data->mlx);

	return (0);
}


/* 	int square_x = 100;
	int square_y = 100;
	int square_size = 100;

	for (int y = square_y; y < square_y + square_size; y++)
	{
		for (int x = square_x; x < square_x + square_size; x++)
		{
			my_mlx_pixel_put(data, x, y, 0x000000FF);
		}
	} */