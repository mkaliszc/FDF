/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:22:31 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/07 23:55:36 by mkaliszc         ###   ########.fr       */
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
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc < 2 || argc > 2)
		return (perror("Too much files or missing map"), 1);
	if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]))) // DOn't if there is letter behind the .fdf !
		return (perror("Wrong file format, correct file format : *.fdf"), 1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// Coordinates and size for the square
	int square_x = 100;
	int square_y = 100;
	int square_size = 100;

	for (int y = square_y; y < square_y + square_size; y++)
	{
		for (int x = square_x; x < square_x + square_size; x++)
		{
			my_mlx_pixel_put(&img, x, y, 0x000000FF);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
