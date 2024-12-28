/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:23:04 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/28 17:17:00 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../src/OctoLIB/include/libft.h"
# include <errno.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/XKBlib.h>

# define ANGLE 0.523599
# define HEIGHT 1080
# define WIDTH 1920
# define HEIGHT 1080
# define LENGTH 1920
# define ESCAPE XK_Escape
# define MOUSE_UP 5
# define MOUSE_DOWN 4
# define KEY_UP 65362
# define KEY_DOWN 65364
# define A_KEY XK_a
# define D_KEY XK_d
# define W_KEY XK_w
# define S_KEY XK_s
# define T_KEY XK_t
# define I_KEY XK_i

typedef enum e_proj
{
	ISO,
	TOP
}	t_proj;

typedef struct s_point
{
	double	x;
	double	y;
	int		z;
	double	delta_x;
	double	delta_y;
	int		steps;
	double	x_increment;
	double	y_increment;
}			t_point;

typedef struct s_data
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
	int		coef;
	int		shift_x;
	int		shift_y;
	t_proj	proj_type;
	t_point	curr;
}			t_data;

void	init_matrix(char *file_name, t_data *data);
void	check_file_name(char *file_name);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_point	iso_proj(double x, double y, double z, t_data *data);
void	draw_map(t_data *data);
void	handle_event(t_data *data);
void	free_data(t_data *data);
t_point	top_proj(double x, double y, double z, t_data *data);

#endif