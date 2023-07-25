/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:37 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/19 07:44:04 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

int	check_if_ended(t_data *data)
{
	if (data->if_collected == data->map.c_count)
		return (1);
	return (0);
}

int	key_event(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13 && check_one(data, keycode))
	{
		data->move_number++;
		data->img.num_player = 0;
	}
	else if (keycode == 0 && check_two(data, keycode))
	{
		data->move_number++;
		data->img.num_player = 1;
	}
	else if (keycode == 1 && check_three(data, keycode))
	{
		data->move_number++;
		data->img.num_player = 2;
	}
	else if (keycode == 2 && check_four(data, keycode))
	{
		data->move_number++;
		data->img.num_player = 3;
	}
	put_xpm(data);
	return (0);
}

int	close_game(t_data *data)
{
	mlx_destroy_window(data->img.mlx, data->img.win);
	exit(0);
}

void	all_hooks(t_data *data)
{
	mlx_hook(data->img.win, 2, 0, key_event, data);
	mlx_loop_hook(data->img.mlx, animation_all, data);
	mlx_hook(data->img.win, 17, 0, close_game, data);
}
