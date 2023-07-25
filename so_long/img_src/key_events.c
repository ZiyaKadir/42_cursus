/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <zktokluoglu>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:37 by ztokluog          #+#    #+#             */
/*   Updated: 2023/05/22 09:07:23 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

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
		ft_printf("Move Number: %d\n", data->move_number);
	}
	else if (keycode == 0 && check_two(data, keycode))
	{
		data->move_number++;
		ft_printf("Move Number: %d\n", data->move_number);
	}
	else if (keycode == 1 && check_three(data, keycode))
	{
		data->move_number++;
		ft_printf("Move Number: %d\n", data->move_number);
	}
	else if (keycode == 2 && check_four(data, keycode))
	{
		data->move_number++;
		ft_printf("Move Number: %d\n", data->move_number);
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
	mlx_hook(data->img.win, 17, 0, close_game, data);
}
