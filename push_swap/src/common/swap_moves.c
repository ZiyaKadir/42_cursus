/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <ztokluog@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:11:01 by ztokluog          #+#    #+#             */
/*   Updated: 2023/06/11 08:11:02 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

void	ft_sa(t_stacks *stack, int print)
{
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few numbers in Stack A.\n");
		return ;
	}
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (print == OPT)
		ft_printf("sa\n");
}

void	ft_sb(t_stacks *stack, int print)
{
	int	tmp;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few numbers in Stack B.\n");
		return ;
	}
	tmp = 0;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (print == OPT)
		ft_printf("sb\n");
}

void	ft_ss(t_stacks *stack, int print)
{
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few numbers in stacks.\n");
		return ;
	}
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (print == OPT)
		ft_printf("ss\n");
}
