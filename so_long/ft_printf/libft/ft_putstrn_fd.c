/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:14:10 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/17 14:36:22 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrn_fd(char *s, int fd, int n)
{
	if (s != NULL)
		return ((int)write(fd, s, n));
	return (0);
}
