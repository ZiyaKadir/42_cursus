/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <ztokluog@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:15:09 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/17 00:16:28 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (!s)
		return (0);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub || !s)
		return (NULL);
	while (s[i] && i < len + start && j < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = 0;
	return (sub);
}
