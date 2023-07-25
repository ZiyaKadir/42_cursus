/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:31 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/19 08:04:40 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	put_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->img.path_img = mlx_xpm_file_to_image(data->img.mlx, "./xpm/path.xpm",
			&data->img.img_width, &data->img.img_height);
	while (i < data->map.rc)
	{
		j = 0;
		while (j < data->map.cc)
		{
			mlx_put_image_to_window(data->img.mlx, data->img.win,
				data->img.path_img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	init_mlx(t_data *data)
{
	data->img.mlx = mlx_init();
	data->img.win = mlx_new_window(data->img.mlx, data->map.cc * 32,
			data->map.rc * 32, "so_long");
}

void	init_img(t_data *data)
{
	put_background(data);
	data->img.player_img = mlx_xpm_file_to_image(data->img.mlx,
			"./xpm/warrior.xpm", &data->img.img_width, &data->img.img_height);
	data->img.wall_img = mlx_xpm_file_to_image(data->img.mlx,
			"./xpm/wall.xpm", &data->img.img_width, &data->img.img_height);
	data->img.chest_img = mlx_xpm_file_to_image(data->img.mlx,
			"./xpm/chest.xpm", &data->img.img_width, &data->img.img_height);
	data->img.gate_img = mlx_xpm_file_to_image(data->img.mlx,
			"./xpm/gate.xpm", &data->img.img_width, &data->img.img_height);
}

void	free_images(t_data *data)
{
	mlx_destroy_image(data->img.mlx, data->img.gate_img);
	mlx_destroy_image(data->img.mlx, data->img.path_img);
	mlx_destroy_image(data->img.mlx, data->img.chest_img);
	mlx_destroy_image(data->img.mlx, data->img.player_img);
	mlx_destroy_image(data->img.mlx, data->img.wall_img);
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
			if (data->map.map[data->i][data->j] == '1')
				mlx_put_image_to_window(data->img.mlx, data->img.win,
					data->img.wall_img, data->j * 32, data->i * 32);
			else if (data->map.map[data->i][data->j] == 'P')
				mlx_put_image_to_window(data->img.mlx, data->img.win,
					data->img.player_img, data->j * 32, data->i * 32);
			else if (data->map.map[data->i][data->j] == 'C')
				mlx_put_image_to_window(data->img.mlx, data->img.win,
					data->img.chest_img, data->j * 32, data->i * 32);
			else if (data->map.map[data->i][data->j] == 'E')
				mlx_put_image_to_window(data->img.mlx, data->img.win,
					data->img.gate_img, data->j * 32, data->i * 32);
			data->j++;
		}
		data->i++;
	}
	all_hooks(data);
}
