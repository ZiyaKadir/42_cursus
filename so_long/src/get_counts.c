/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_counts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <zktokluoglu>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:45:02 by ztokluog          #+#    #+#             */
/*   Updated: 2023/05/22 08:55:14 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	get_coin_count(t_data *data)
{
	int	i;
	int	j;
	int	coin_count;

	i = 0;
	coin_count = 0;
	while (i < data->map.rc)
	{
		j = 0;
		while (j < data->map.cc)
		{
			if (data->map.map[i][j] == 'C')
				coin_count++;
			j++;
		}
		i++;
	}
	data->map.c_count = coin_count;
}

void	get_exit_count(t_data *data)
{
	int	i;
	int	j;
	int	exit_count;

	i = 0;
	exit_count = 0;
	while (i < data->map.rc)
	{
		j = 0;
		while (j < data->map.cc)
		{
			if (data->map.map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	data->map.e_count = exit_count;
}

void	get_char_count(t_data *data)
{
	int	i;
	int	j;
	int	char_count;

	i = 0;
	char_count = 0;
	while (i < data->map.rc)
	{
		j = 0;
		while (j < data->map.cc)
		{
			if (data->map.map[i][j] == 'P')
			{
				data->map.pr = i;
				data->map.pc = j;
				char_count++;
			}
			j++;
		}
		i++;
	}
	data->map.ch_count = char_count;
}

int	check_counts(t_data *data)
{
	get_coin_count(data);
	get_exit_count(data);
	get_char_count(data);
	if (data->map.ch_count != 1 || data->map.c_count < 1
		|| data->map.e_count < 1)
		return (0);
	else
		return (1);
}
