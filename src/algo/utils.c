/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:10:08 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/19 14:55:10 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->matrix)
		free_matrix(data);
	free(data);
}
