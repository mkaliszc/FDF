/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:19:59 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/28 17:20:39 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file_name(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (ft_strncmp(file_name + len - 4, ".fdf", 4) != 0)
	{
		ft_putstr_fd("Wrong file format, correct format : '.fdf'\n", 2);
		exit(1);
	}
}
