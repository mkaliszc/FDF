/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:23:04 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/16 21:00:46 by mkaliszc         ###   ########.fr       */
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
# define HEIGHT 1080
# define WIDTH 1920
# define ZOOM 20
# define WINDOW_HEIGHT 1080
# define WINDOW_LENGTH 1920
# define ESCAPE XK_Escape

typedef struct s_point
{
	double  x;
	double  y;
	int     z;
	double  delta_x;
	double  delta_y;
	int     steps;
	double  x_increment;
	double  y_increment;
}	t_point;

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
	double	zoom;
	int		x;
	int		y;
	t_point current;
}			t_data;

void	init_matrix(char *file_name, t_data *data);
int		check_file_name(char *file_name);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_point	iso_proj(double x, double y, double z);
void	draw_map(t_data *data);

#endif