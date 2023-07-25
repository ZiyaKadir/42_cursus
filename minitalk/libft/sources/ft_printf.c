/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <zktokluoglu>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:34:04 by ztokluog          #+#    #+#             */
/*   Updated: 2023/04/19 13:34:08 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	base_c(unsigned long var, char *base, int first)
{
	char			c;
	size_t			len;
	static size_t	i;

	i = 0;
	len = ft_strlen(base);
	c = base[var % len];
	if (var == 0 && first)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	else if (var != 0)
	{
		base_c(var / len, base, 0);
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}

static int	put_pointer(unsigned long x)
{
	int	var1;

	var1 = ft_putstr_fd("0x", 1, 0);
	var1 += base_c(x, "0123456789abcdef", 1);
	return (var1);
}

static int	ftype(char c, void *arg)
{
	if (arg == NULL && c == 's')
		return (ft_putstr_fd("(null)", 1, 0));
	else if (c == 's')
		return (ft_putstr_fd((char *)arg, 1, 0));
	else if (c == 'c')
		return (ft_putchar_fd((char)arg, 1));
	else if (c == 'p')
		return (put_pointer((unsigned long) arg));
	else if (c == 'i' || c == 'd')
		return (ft_putstr_fd(ft_itoa((int)arg), 1, 1));
	else if (c == 'u')
		return (ft_putstr_fd(ft_uitoa((unsigned int)arg), 1, 1));
	else if (c == 'x')
		return (base_c((unsigned int)arg, "0123456789abcdef", 1));
	else if (c == 'X')
		return (base_c((unsigned int)arg, "0123456789ABCDEF", 1));
	else
		return (ft_putchar_fd(c, 1));
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	size_t		k;

	va_start(args, str);
	k = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			if (str[++i] == '%')
				k += ft_putchar_fd('%', 1);
			else if (!str[i])
				break ;
			else
				k += ftype(str[i], va_arg(args, void *));
		}
		else
			k += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (k);
}
