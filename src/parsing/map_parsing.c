/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:15:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/08 00:37:01 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**fill_matrix(char **args, int **matrix)
{
	char	**splited;
	char	*line;
	int		fd;
	int		x;
	int		y;

	fd = open(args[1], O_RDONLY);
	y = 0;
	while (line != NULL)
	{
		x = 0;
		line = get_next_line(fd);
		splited = ft_split(line, ' ');
		while (splited[x] != NULL)
		{
			matrix[y][x] = ft_atoi(splited[x]);
			x++;
		}
		y++;
	}
	if (matrix == NULL)
		return(perror("Error while creating the matrix"), NULL);
}
