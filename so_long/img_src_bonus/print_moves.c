/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 06:32:01 by Ziya Kadir TOKLU  #+#    #+#             */
/*   Updated: 2023/07/19 07:44:11 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

void	print_moves(t_data *data)
{
	char	*moves;

	mlx_put_image_to_window(data->img.mlx, data->img.win,
		data->img.info_img, 0 * 48, 0 * 48);
	moves = ft_itoa(data->move_number);
	mlx_string_put(data->img.mlx, data->img.win, 15, 24, 0x545252, moves);
	free(moves);
	moves = NULL;
}
