/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:44:45 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/18 17:36:13 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_data *data)
{
	int	r;
	int	c;

	r = 0;
	while (data->map.map[r] != NULL)
	{
		c = 0;
		while (data->map.map[r][c])
		{
			if ((r == 0 && data->map.map[r][c] != '1')
				|| (c == 0 && data->map.map[r][c] != '1')
				|| (r == data->map.rc - 1 && data->map.map[r][c] != '1')
				|| (c == data->map.cc - 1 && data->map.map[r][c] != '1'))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}

int	check_charachters(t_data *data)
{
	char	temp;
	int		row;
	int		column;

	row = 0;
	while (data->map.map[row] != NULL)
	{
		column = 0;
		while (data->map.map[row][column])
		{
			temp = data->map.map[row][column];
			if (temp != '0' && temp != '1' && temp != 'C'
				&& temp != 'E' && temp != 'P' && temp != 'V' && temp != '\n')
				return (0);
			column++;
		}
		row++;
	}
	return (1);
}

int	check_rectangular(t_data *data)
{
	int		row;
	int		column;

	row = 0;
	while (data->map.map[row] != NULL)
	{
		column = 0;
		while (data->map.map[row][column])
			column++;
		if (column != data->map.cc)
			return (0);
		row++;
	}
	return (1);
}
