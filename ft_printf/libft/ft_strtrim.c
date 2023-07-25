/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <ztokluog@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:15:06 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/17 00:14:18 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	i = 0;
	j = ft_strlen(s1) - 1;
	while ((ft_strchr(set, s1[i])) && s1[i])
		i++;
	if (i == ft_strlen(s1) || *s1 == '\0')
		return (ft_strdup(""));
	while ((ft_strchr(set, s1[j])) && j > 0)
		j--;
	res = ft_substr(s1, (unsigned int)i, j - i + 1);
	return (res);
}
