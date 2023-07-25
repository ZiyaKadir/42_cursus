/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:14 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/19 08:04:07 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_printf("Error\n Argument number is not given correctly\n");
		exit(1);
	}
	init_data(&data);
	create_board(argv[1], data);
	if (!check_all(data))
	{
		ft_free(data);
		exit(0);
	}
	init_mlx(data);
	put_xpm(data);
	all_hooks(data);
	mlx_loop(data->img.mlx);
	ft_free(data);
	free_images(data);
	return (0);
}
