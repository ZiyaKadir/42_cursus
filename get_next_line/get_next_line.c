/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <ztokluog@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:10:23 by ztokluog          #+#    #+#             */
/*   Updated: 2023/03/10 15:11:44 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = read_file(fd, save);
	if (!save)
		return (NULL);
	ret = get_line(save);
	if (!save[0])
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = clear_save(save);
	return (ret);
}

char	*clear_save(char *save)
{
	int		nullen;
	char	*new;
	int		i;
	int		len;

	i = 0;
	nullen = ft_strlen(save);
	len = 0;
	while (save[len] && save[len] != '\n')
		len++;
	new = malloc(((nullen - len) + 1) * sizeof(char));
	while (i < nullen - len)
	{
		new[i] = save[len + i + 1];
		++i;
	}
	new[i] = 0;
	free(save);
	return (new);
}

char	*get_line(char *save)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!save[0])
		return (NULL);
	while (save[len] && save[len] != '\n')
		len++;
	if (save[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		line[i] = save[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*read_file(int fd, char *save)
{
	char	*buff;
	int		sonuc;

	sonuc = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	while (!ft_strchr(save, '\n') && sonuc != 0)
	{
		sonuc = read(fd, buff, BUFFER_SIZE);
		if (sonuc == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[sonuc] = 0;
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}
