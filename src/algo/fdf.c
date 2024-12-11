/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:51:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/11 20:23:42 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_proj(int *x, int *y, int z)
{
	int	tmp;

	tmp = *x;
	*x = (tmp - *y) * cos(ANGLE);
	*y = (tmp + *y) * sin(ANGLE) - z;
}

void draw_line(t_data *data, int x0, int y0, int x1, int y1) {
    // Calculate differences
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    
    // Determine direction of line
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    
    // Initial error
    int err = dx - dy;
    
    // Current point
    int x = x0;
    int y = y0;
    
    while (1) {
        // Plot pixel using MiniLibX
        mlx_pixel_put(data->mlx, data->window, x, y, 0x000000FF);
        
        // Check if we've reached the end point
        if (x == x1 && y == y1)
            break;
        
        // Calculate error for next iteration
        int e2 = 2 * err;
        
        // Adjust x coordinate
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        
        // Adjust y coordinate
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}