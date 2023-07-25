/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 04:47:57 by Ziya Kadir TOKLU  #+#    #+#             */
/*   Updated: 2023/07/19 04:51:44 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	static char	*str[2000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = read_from_file(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = clear_str(str[fd]);
	return (line);
}
