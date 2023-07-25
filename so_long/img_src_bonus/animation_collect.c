/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_collect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:07:09 by Ziya Kadir TOKLU  #+#    #+#             */
/*   Updated: 2023/07/19 07:43:39 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

void	arrange_xpm_position(t_data *data, int position)
{
	data->img.number_chest = position;
	put_xpm(data);
}

static void	rotation_key(t_data *data, int i)
{
	if (i == 0)
		arrange_xpm_position(data, 0);
	else if (i == 2500)
		arrange_xpm_position(data, 1);
	else if (i == 4500)
		arrange_xpm_position(data, 2);
	else if (i == 6500)
		arrange_xpm_position(data, 3);
	else if (i == 8500)
		arrange_xpm_position(data, 4);
	else if (i == 10500)
		arrange_xpm_position(data, 5);
	else if (i == 12500)
		arrange_xpm_position(data, 0);
}

static void	animation_key(t_data *data)
{
	static int	counter;

	data->i = 0;
	data->j = 0;
	while (data->i < data->map.rc)
	{
		data->j = 0;
		while (data->j < data->map.cc)
		{
			if (data->map.map[data->i][data->j] == 'C')
				rotation_key(data, counter);
			data->j++;
		}
		data->i++;
	}
	counter++;
	if (counter > 12500)
		counter = 0;
}

void	animation_collect(t_data *data)
{
	animation_key(data);
}
