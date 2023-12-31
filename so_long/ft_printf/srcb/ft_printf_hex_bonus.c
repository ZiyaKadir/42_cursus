/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <ztokluog@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:46:45 by ztokluog          #+#    #+#             */
/*   Updated: 2023/07/16 23:46:50 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"

static char	*ft_sharp(t_format fmt)
{
	if (fmt.specifier == 'X')
		return ("0X");
	return ("0x");
}

static int	ft_recursive_hex(t_format fmt, size_t n, size_t iteration)
{
	int		count;
	int		rem;
	char	c;
	char	*hextype;

	if (fmt.specifier != 'X')
		hextype = HEXALOW;
	else
		hextype = HEXAUP;
	count = 0;
	if (n > 0 || !iteration)
	{
		rem = n % 16;
		c = hextype[rem];
		n /= 16;
		iteration = 1;
		count += ft_recursive_hex(fmt, n, iteration);
		count += ft_putnchar_fd(c, 1, 1);
	}
	return (count);
}

int	ft_print_x(t_format fmt, va_list ap)
{
	int				count;
	unsigned int	n;
	int				len;

	count = 0;
	n = va_arg(ap, unsigned int);
	len = ft_count_digit_base(n, 16);
	len *= !(!n && !fmt.prec && fmt.dot);
	if (fmt.prec < 0 || fmt.prec < len || !fmt.dot)
		fmt.prec = len;
	if (fmt.sharp && n)
		fmt.width -= 2;
	count += ft_putstrn_fd(ft_sharp(fmt), 1, 2 * (fmt.sharp && fmt.zero && n));
	if (!fmt.minus && fmt.zero && fmt.width > fmt.prec && (!fmt.dot
			|| fmt.neg_prec))
		count += ft_putnchar_fd('0', 1, (fmt.width - fmt.prec));
	else if (!fmt.minus && fmt.width > fmt.prec)
		count += ft_putnchar_fd(' ', 1, (fmt.width - fmt.prec));
	count += ft_putstrn_fd(ft_sharp(fmt), 1, 2 * (fmt.sharp && !fmt.zero && n));
	count += ft_putnchar_fd('0', 1, fmt.prec - len);
	if (len)
		count += ft_recursive_hex(fmt, n, n);
	if (fmt.minus && fmt.width > fmt.prec)
		count += ft_putnchar_fd(' ', 1, fmt.width - fmt.prec);
	return (count);
}

int	ft_print_p(t_format fmt, va_list ap)
{
	int		count;
	size_t	n;
	int		length;

	count = 0;
	n = va_arg(ap, size_t);
	length = ft_count_digit_base(n, 16);
	fmt.width -= 2;
	if (!fmt.minus)
		count += ft_putnchar_fd(' ', 1, fmt.width - length);
	count += ft_putstrn_fd("0x", 1, 2);
	if (length)
		count += ft_recursive_hex(fmt, n, n);
	if (fmt.minus)
		count += ft_putnchar_fd(' ', 1, fmt.width - length);
	return (count);
}
