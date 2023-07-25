/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <ztokluog@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:46:24 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/17 01:45:11 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (*++str)
				count += ft_parse((char *)str, ap);
			while (*str && !ft_strchr(SPECIFIERS, *str))
				str++;
		}
		else
			count += ft_putnchar_fd(*str, 1, 1);
		str++;
	}
	va_end(ap);
	return (count);
}

int	ft_print_format(t_format fmt, va_list ap)
{
	int	count;

	count = 0;
	if (fmt.specifier == 'c' || fmt.specifier == '%')
		count = ft_print_c(fmt, ap);
	if (fmt.specifier == 's')
		count = ft_print_s(fmt, ap);
	if (fmt.specifier == 'd' || fmt.specifier == 'i' || fmt.specifier == 'u')
		count = ft_print_d_i_u(fmt, ap);
	if (fmt.specifier == 'X' || fmt.specifier == 'x')
		count = ft_print_x(fmt, ap);
	if (fmt.specifier == 'p')
		count = ft_print_p(fmt, ap);
	return (count);
}
