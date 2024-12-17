/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:23:28 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/17 22:30:21 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	iso_proj(double x, double y, double z, t_data *data)
{
	t_point	curr;

	curr.x = (x - y) * cos(ANGLE) * data->zoom + LENGTH / 2;
	curr.y = ((x + y) * sin(ANGLE) - z * data->coef) * data->zoom + HEIGHT / 2;
	curr.z = z;
	return (curr);
}

t_point	top_proj(double x, double y, double z, t_data *data)
{
	t_point	p;

	p.x = x * data->zoom + LENGTH / 2;
	p.y = y * data->zoom + HEIGHT / 2;
	p.z = z;
	return (p);
}