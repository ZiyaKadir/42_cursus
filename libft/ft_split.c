/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:14:16 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/17 14:36:23 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**one_more(char **arr, unsigned int size)
{
	char			**res;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	res = (char **)ft_calloc((size + 2), sizeof(char *));
	if (arr != NULL && res != NULL)
	{
		while (i < size)
		{
			j = 0;
			res[i] = (char *)ft_calloc((ft_strlen(arr[i]) + 1), sizeof(char));
			while (arr[i][j])
			{
				res[i][j] = arr[i][j];
				j++;
			}
			res[i][j] = arr[i][j];
			free(arr[i]);
			i++;
		}
		res[i] = 0;
	}
	free(arr);
	return (res);
}

static int	count(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**res;
	unsigned int	size;

	size = 0;
	i = 0;
	res = (char **)ft_calloc(sizeof(char *), 1);
	if (!(res) || !s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			res = one_more(res, size++);
			res[size - 1] = ft_substr(s, i, count(&s[i], c));
			i += count(&s[i], c);
		}
	}
	return (res);
}
