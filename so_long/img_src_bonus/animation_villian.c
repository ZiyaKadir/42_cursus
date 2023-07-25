/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_villian.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:07:05 by Ziya Kadir TOKLU  #+#    #+#             */
/*   Updated: 2023/07/19 16:36:14 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

double	*allocate_distances(void)
{
	double	*distances;

	distances = (double *)malloc(4 * sizeof(double));
	if (distances == NULL)
	{
		exit(EXIT_FAILURE);
	}
	return (distances);
}

int	generate_direction(t_data *data, int villain_y, int villain_x)
{
	double	*distances;
	int		direction;

	distances = allocate_distances();
	distances[0] = calculate_distance(villain_x, villain_y - 1, data->map.pc,
			data->map.pr);
	distances[1] = calculate_distance(villain_x, villain_y + 1, data->map.pc,
			data->map.pr);
	distances[2] = calculate_distance(villain_x - 1, villain_y, data->map.pc,
			data->map.pr);
	distances[3] = calculate_distance(villain_x + 1, villain_y, data->map.pc,
			data->map.pr);
	direction = find_closest_direction(data, villain_y, villain_x, distances);
	free(distances);
	return (direction);
}

static void	move_villian(t_data *data, int y, int x)
{
	int	direction;
	int	new_y;
	int	new_x;

	new_y = y;
	new_x = x;
	direction = generate_direction(data, y, x);
	if (direction == 0 && is_valid_move(data, y - 1, x))
		new_y = y - 1;
	else if (direction == 1 && is_valid_move(data, y + 1, x))
		new_y = y + 1;
	else if (direction == 2 && is_valid_move(data, y, x - 1))
		new_x = x - 1;
	else if (direction == 3 && is_valid_move(data, y, x + 1))
		new_x = x + 1;
	if (is_valid_move(data, new_y, new_x))
	{
		data->map.map[y][x] = '0';
		data->map.map[new_y][new_x] = 'V';
	}
}

void	animation_villian(t_data *data)
{
	static int	counter;

	data->i = 0;
	data->j = 0;
	if (counter == 7500)
	{
		while (data->i < data->map.rc)
		{
			data->j = 0;
			while (data->j < data->map.cc)
			{
				if (data->map.map[data->i][data->j] == 'V')
					move_villian(data, data->i, data->j);
				data->j++;
			}
			data->i++;
		}
		put_xpm(data);
	}
	counter++;
	if (counter > 7500)
		counter = 0;
}
