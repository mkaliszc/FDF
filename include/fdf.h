/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:23:04 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/12 15:29:02 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../src/OctoLIB/include/libft.h"
# include <errno.h>
# include <math.h>
# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/XKBlib.h>

# define ANGLE 0.523599

typedef struct	s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	err2;
}	t_line;

typedef struct	s_data
{
	void	*img;
	void	*mlx;
	void	*window;
	char	*addr;
	int		**matrix;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map_height;
	int		map_length;
}			t_data;

void	init_matrix(char *file_name, t_data *data);
int		check_file_name(char *file_name);
void	draw_line(t_data *data, int x0, int y0, int x1, int y1, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	iso_proj(int *x, int *y, int z);

#endif