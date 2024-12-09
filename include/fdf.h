/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:23:04 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/09 18:16:37 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../src/OctoLIB/include/libft.h"
# include <errno.h>
# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/XKBlib.h>

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

#endif