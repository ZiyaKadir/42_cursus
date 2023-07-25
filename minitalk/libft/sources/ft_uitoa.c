/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <zktokluoglu>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:34:38 by ztokluog          #+#    #+#             */
/*   Updated: 2023/04/19 13:35:14 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	count_digit(long n)
{
	size_t	c;

	c = 0;
	if (n < 0)
	{
		n *= -1;
		c++;
	}
	while (n >= 0)
	{
		n /= 10;
		c++;
		if (n == 0)
			break ;
	}
	return (c);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	n2;
	size_t			len;
	char			*toarray;

	n2 = n;
	len = count_digit(n2);
	toarray = malloc(sizeof(char) * (len + 1));
	if (!toarray)
		return (NULL);
	toarray[len--] = '\0';
	while (n2 >= 0)
	{
		toarray[len] = (n2 % 10) + '0';
		n2 /= 10;
		len--;
		if (n2 == 0)
			break ;
	}
	return (toarray);
}
