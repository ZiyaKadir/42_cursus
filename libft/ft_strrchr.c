/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <ztokluog@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:19:39 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/17 00:15:49 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	res;

	res = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c % 256)
			res = i;
		i++;
	}
	if (str[i] == c % 256)
		res = i;
	if (res == -1)
		return (NULL);
	else
		return (&((char *)str)[res]);
}
