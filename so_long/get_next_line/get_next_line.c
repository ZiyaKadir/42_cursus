/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 04:47:12 by Ziya Kadir TOKLU  #+#    #+#             */
/*   Updated: 2023/07/19 04:51:26 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*read_from_file(int fd, char *str)
{
	char	*temp;
	int		char_count;

	char_count = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_strchr(str, '\n') && char_count)
	{
		char_count = read(fd, temp, BUFFER_SIZE);
		if (char_count == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[char_count] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_from_file(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = clear_str(str);
	return (line);
}
