/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:44:54 by ztokluog          #+#    #+#             */
/*   Updated: 2023/05/22 01:25:10 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.rc)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
	free(data->map.str_to_map);
	free(data);
}

int	line_count(char *map)
{
	char	*line;
	int		line_count;
	int		fd;

	line_count = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile is not exist!!\n");
		exit(0);
	}
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
	}
	close(fd);
	free(line);
	return (line_count);
}

void	put_map_intro_string(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	line = get_next_line(data->map.fd);
	data->map.str_to_map = malloc((ft_strlen(line) * data->map.rc) + 1);
	data->map.cc = ft_strlen(line) - 1;
	while (line)
	{
		j = 0;
		if (!(data->map.str_to_map))
		{
			ft_free(data);
			exit(0);
		}
		while (line[j])
			data->map.str_to_map[i++] = line[j++];
		free(line);
		line = get_next_line(data->map.fd);
	}
	free(line);
	data->map.str_to_map[i] = '\0';
}

void	create_board(char *path, t_data *data)
{
	data->map.path = path;
	data->map.rc = line_count(path);
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
	{
		ft_printf("File is not exist\n");
		ft_free(data);
		exit(0);
	}
	else
	{
		put_map_intro_string(data);
		data->map.map = ft_split(data->map.str_to_map, '\n');
		close(data->map.fd);
	}
}
