/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 06:10:01 by Ziya Kadir TOKLU  #+#    #+#             */
/*   Updated: 2023/07/19 10:21:53 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

void	init_mlx(t_data *data)
{
	data->img.mlx = mlx_init();
	data->img.win = mlx_new_window(data->img.mlx, data->map.cc * 48,
			data->map.rc * 48, "so_long");
}

void	put_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->img.path_img = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/floor/floor.xpm",
			&data->img.img_width,
			&data->img.img_height);
	while (i < data->map.rc)
	{
		j = 0;
		while (j < data->map.cc)
		{
			mlx_put_image_to_window(data->img.mlx, data->img.win,
				data->img.path_img, j * 48, i * 48);
			j++;
		}
		i++;
	}
}

void	init_img_key_s(t_data *data)
{
	data->img.chest_img[0] = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/collect/key_g1.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.chest_img[1] = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/collect/key_g2.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.chest_img[2] = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/collect/key_g3.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.chest_img[3] = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/collect/key_g4.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.chest_img[4] = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/collect/key_g5.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.chest_img[5] = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/collect/key_g6.xpm",
			&data->img.img_width,
			&data->img.img_height);
}

void	init_img_player(t_data *data)
{
	data->img.player_img[0] = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/player/knight_back.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.player_img[1] = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/player/knight_left.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.player_img[2] = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/player/knight_down.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.player_img[3] = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/player/knight_right.xpm",
			&data->img.img_width,
			&data->img.img_height);
}

void	init_img(t_data *data)
{
	put_background(data);
	data->img.chest_img = malloc(sizeof(void *) * 6);
	data->img.player_img = malloc(sizeof(void *) * 10);
	init_img_player(data);
	init_img_key_s(data);
	data->img.info_img = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/ui/info.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.wall_img = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/walls/wall.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.gate_img = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/exit/door_closed.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.villian_img = mlx_xpm_file_to_image(data->img.mlx,
			"./assets/villain/goblin.xpm",
			&data->img.img_width,
			&data->img.img_height);
}
