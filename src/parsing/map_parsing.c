/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:15:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/10 18:35:01 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_length(t_data *data, char *line)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	data->map_length = 0;
	while (tmp[data->map_length] != NULL)
		data->map_length++;
	ft_free_tab(tmp, data->map_length);
}

void	map_dimensions(t_data *data, char *file_name)
{
	char *line;
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error while opening the file"), NULL);
	line = get_next_line(fd);
	get_length(data, line);
	data->map_height = 1;
	while (line != NULL)
	{
		data->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	fill_matrix(int *matrix, char *line)
{
	char	**tmp;
	int		x;

	tmp = ft_split(line, ' ');
	x = 0;
	while (tmp[x] != NULL)
	{
		matrix[x] = ft_atoi(tmp[x]);
		x++;
	}
	ft_free_tab(tmp, x);
}

void	create_matrix(t_data *data, char *file_name)
{
	int		fd;
	char *line;
	int		y;

	y = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error while opening the file"), NULL);
	line = get_next_line(fd);
	while (line != NULL && y < data->map_height)
	{
		fill_matrix(data->matrix[y], line);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	free(line);
}

void	init_matrix(char *file_name, t_data *data)
{
	int		i;

	map_dimensions(data, file_name);
	data->matrix = malloc(sizeof(int *) * data->map_height);
	if (data->matrix == NULL)
		return (NULL);
	i = 0;
	while (i < data->map_height)
	{
		data->matrix[i] = malloc(sizeof(int) * data->map_length);
		if (data->matrix[i] == NULL)
			return(ft_free_matrix(data, i - 1));
		i++;
	}
	ft_create_matrix(data, file_name);
}
