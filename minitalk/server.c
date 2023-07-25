/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <zktokluoglu>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:31:41 by ztokluog          #+#    #+#             */
/*   Updated: 2023/04/19 13:32:03 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft/includes/ft_printf.h"
#include <stdlib.h>
#include <signal.h>

int	g_len;

void	is_completed(int pid)
{
	int	i;

	i = 0;
	while (g_len > i)
	{
		usleep(100);
		kill(pid, SIGUSR1);
		i++;
	}
}

void	set(int *arg, int len)
{
	int	i;

	i = 0;
	while (len - 1 > i)
	{
		arg[i] = 0;
		i++;
	}
	arg[i] = -1;
}

void	write_char(int sig, int *items)
{
	if (!g_len && items[3] != -1)
		set(items, 4);
	if (sig == SIGUSR1)
		items[2] |= (1 << items[1]);
	if (sig == SIGUSR2)
	{
		items[2] |= (0 << items[1]);
		items[0] += 1;
	}
	items[1] += 1;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int		items[4];

	context = NULL;
	write_char(sig, items);
	if (items[1] == 8)
	{
		if (items[0] == 8)
		{
			usleep(100);
			is_completed(info->si_pid);
			set(items, 4);
			return ;
		}
		ft_printf("%c", items[2]);
		g_len++;
		set(items, 4);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					i;

	i = 0;
	g_len = 0;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	ft_printf("pid %d\n", getpid(), 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
/*

void print_binary(unsigned int number)
{
	int i = 0;
	while(i < 8)
	{
		ft_printf("%c",(number & 1) ? '1' : '0');
		number = (number >> 1);
		i++;
	}
}
*/
