/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <zktokluoglu>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:32:40 by ztokluog          #+#    #+#             */
/*   Updated: 2023/04/19 13:32:50 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int		g_count = 0;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_count++;
}

void	send_message(int number, char *str)
{
	int	j;
	int	i;
	int	c;
	int	length;

	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		j = 0;
		c = str[i];
		while (j < 8)
		{
			usleep(100);
			if (c & 1)
				kill(number, SIGUSR1);
			else
				kill(number, SIGUSR2);
			c = (c >> 1);
			j++;
		}
		i++;
	}
}

void	approve(int number)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(100);
		kill(number, SIGUSR2);
		i++;
	}
}

void	approved(int length)
{
	if (length == g_count)
	{
		ft_printf("Received Message\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					number;
	int					length;

	if (argc != 3)
		exit(1);
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	length = ft_strlen(argv[2]);
	number = ft_atoi(argv[1]);
	send_message(number, argv[2]);
	usleep(200);
	approve(number);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		pause();
		approved(length);
	}
}
