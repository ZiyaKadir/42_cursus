/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <ztokluog@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:37:27 by ztokluog          #+#    #+#             */
/*   Updated: 2022/07/28 18:45:46 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (index < (n - 1) && s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			break ;
		index++;
	}
	return (((unsigned char *)s1)[index] - ((unsigned char *)s2)[index]);
}
