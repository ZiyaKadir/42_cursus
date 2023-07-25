/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ziya Kadir TOKLUOGLU <zktokluoglu@gmail.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 04:47:19 by Ziya Kadir TOKLU  #+#    #+#             */
/*   Updated: 2023/07/19 04:48:52 by Ziya Kadir TOKLU ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
char	*read_from_file(int fd, char *str);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(const char *str);
char	*get_line(char *str);
char	*clear_str(char *str);
char	*ft_strdup(const char *str);

#endif
