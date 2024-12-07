/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:23:04 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/08 00:40:03 by mkaliszc         ###   ########.fr       */
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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;



#endif