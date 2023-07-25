/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:31 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/19 15:14:27 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

void	free_images(t_data *data)
{
	int	i;

	mlx_destroy_image(data->img.mlx, data->img.gate_img);
	mlx_destroy_image(data->img.mlx, data->img.path_img);
	i = 0;
	while (i++ < 5)
		mlx_destroy_image(data->img.mlx,
			data->img.chest_img[i]);
	free(data->img.chest_img);
	i = 0;
	while (i++ < 3)
		mlx_destroy_image(data->img.mlx,
			data->img.player_img[i]);
	free(data->img.player_img);
	mlx_destroy_image(data->img.mlx, data->img.wall_img);
}

void	put_xpm_key(t_data *data)
{
	if (data->img.number_chest == 0)
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.chest_img[0], data->j * 48, data->i * 48);
	else if (data->img.number_chest == 1)
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.chest_img[1], data->j * 48, data->i * 48);
	else if (data->img.number_chest == 2)
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.chest_img[2], data->j * 48, data->i * 48);
	else if (data->img.number_chest == 3)
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.chest_img[3], data->j * 48, data->i * 48);
	else if (data->img.number_chest == 4)
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.chest_img[4], data->j * 48, data->i * 48);
	else if (data->img.number_chest == 5)
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.chest_img[5], data->j * 48, data->i * 48);
}

void	put_xpm_player(t_data *data)
{
	if (data->img.num_player == 0)
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.player_img[0], data->j * 48, data->i * 48);
	else if (data->img.num_player == 1)
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.player_img[1], data->j * 48, data->i * 48);
	else if (data->img.num_player == 2)
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.player_img[2], data->j * 48, data->i * 48);
	else if (data->img.num_player == 3)
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.player_img[3], data->j * 48, data->i * 48);
}

void	put_xpm_image(t_data *data)
{
	if (data->map.map[data->i][data->j] == '1')
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.wall_img, data->j * 48, data->i * 48);
	else if (data->map.map[data->i][data->j] == 'P')
		put_xpm_player(data);
	else if (data->map.map[data->i][data->j] == 'C')
		put_xpm_key(data);
	else if (data->map.map[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.gate_img, data->j * 48, data->i * 48);
	else if (data->map.map[data->i][data->j] == 'V')
		mlx_put_image_to_window(data->img.mlx, data->img.win,
			data->img.villian_img, data->j * 48, data->i * 48);
}

void	put_xpm(t_data *data)
{
	init_img(data);
	data->i = 0;
	while (data->map.map[data->i] != NULL)
	{
		data->j = 0;
		while (data->map.map[data->i][data->j])
		{
			print_moves(data);
			put_xpm_image(data);
			data->j++;
		}
		data->i++;
	}
	free_images(data);
}
