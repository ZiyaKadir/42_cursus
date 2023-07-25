/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <zktokluoglu>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:33:07 by ztokluog          #+#    #+#             */
/*   Updated: 2023/04/19 13:33:13 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
size_t	ft_strlen(char *chr);
size_t	ft_putstr_fd(char *s, int fd, int free);
int		ft_putchar_fd(char c, int fd);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *str);
#endif
