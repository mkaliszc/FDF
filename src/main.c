/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:22:31 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/09 18:03:05 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2 || argc > 2)
		return (perror("Too much files or missing map"), 1);
	else
	{
		if (check_arg(argv[1]))
			return (perror("Wrong file format"), 1);
		data = malloc(sizeof(t_data));
		if (data == NULL)
			return (perror("allocation error for data"), 1);
		init_matrix(argv[1], data);
		data->mlx = mlx_init();
		data->window = mlx_new_window(data->mlx, 1920, 1080, "FDF");
		data->img = mlx_new_image(data->mlx, 500, 500);
		data->addr = mlx_get_data_addr(data->img, data->bits_per_pixel,data->line_length, data->endian);
		mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
		mlx_loop(data->mlx);
	}
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