/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:46:00 by Ziya Kadir TOKLU  #+#    #+#             */
/*   Updated: 2023/07/17 12:46:01 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_c(t_format fmt, va_list ap)
{
	char	c;
	int		count;

	count = 0;
	if (fmt.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	fmt.prec = 1;
	if (!fmt.minus)
		count += ft_putnchar_fd(' ', 1, fmt.width - fmt.prec);
	count += ft_putnchar_fd(c, 1, 1);
	if (fmt.minus)
		count += ft_putnchar_fd(' ', 1, fmt.width - fmt.prec);
	return (count);
}

int	ft_print_s(t_format fmt, va_list ap)
{
	char	*string;
	int		count;
	int		len;

	count = 0;
	string = va_arg(ap, char *);
	if (!string)
		string = "(null)";
	len = (int)ft_strlen(string);
	if (!fmt.dot || fmt.prec > len || fmt.prec < 0)
		fmt.prec = len;
	if (!fmt.minus)
		count += ft_putnchar_fd(' ', 1, fmt.width - fmt.prec);
	count += ft_putstrn_fd(string, 1, fmt.prec);
	if (fmt.minus)
		count += ft_putnchar_fd(' ', 1, fmt.width - fmt.prec);
	return (count);
}
