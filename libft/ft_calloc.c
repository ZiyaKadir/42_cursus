/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:48:21 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/17 14:35:49 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	res = malloc(count * size);
	if (!res)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)res)[i] = 0;
		i++;
	}
	return (res);
}
