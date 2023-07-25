/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <zktokluoglu>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:34:27 by ztokluog          #+#    #+#             */
/*   Updated: 2023/04/19 13:35:07 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_putstr_fd(char *s, int fd, int free_f)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = s;
	while (s[i] != 0)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	if (tmp != NULL && free_f)
		free(tmp);
	return (i);
}
