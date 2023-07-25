/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:06:37 by Ziya Kadir TOKLU  #+#    #+#             */
/*   Updated: 2023/07/19 16:29:22 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

int	is_valid_move(t_data *data, int new_y, int new_x)
{
	return (new_y >= 0 && new_y < data->map.rc && new_x >= 0
		&& new_x < data->map.cc && data->map.map[new_y][new_x] != 'P'
		&& data->map.map[new_y][new_x] != '1'
		&& data->map.map[new_y][new_x] != 'E'
		&& data->map.map[new_y][new_x] != 'V'
		&& data->map.map[new_y][new_x] != 'C');
}

double	calculate_distance(int y1, int x1, int y2, int x2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	assign_y(int *next_villain_y, int *villain_y, int *i)
{
	if (*i == 0)
		*next_villain_y = *villain_y - 1;
	else if (*i == 1)
		*next_villain_y = *villain_y + 1;
}

void	assign_x(int *next_villain_x, int *villain_x, int *i)
{
	if (*i == 2)
		*next_villain_x = *villain_x - 1;
	else if (*i == 3)
		*next_villain_x = *villain_x + 1;
}

int	find_closest_direction(t_data *data, int villain_y, int villain_x,
		double *distances)
{
	double	min_distance;
	int		direction;
	int		next_villain_y;
	int		next_villain_x;
	int		i;

	next_villain_x = villain_x;
	next_villain_y = villain_y;
	min_distance = 300;
	direction = -1;
	i = 0;
	while (i < 4)
	{
		assign_y(&next_villain_y, &villain_y, &i);
		assign_x(&next_villain_x, &villain_x, &i);
		if (distances[i] < min_distance && is_valid_move(data, next_villain_y,
				next_villain_x))
		{
			min_distance = distances[i];
			direction = i;
		}
		i++;
	}
	return (direction);
}
