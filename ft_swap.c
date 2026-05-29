/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_values(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
	tmp = a->index;
	a->index = b->index;
	b->index = tmp;
}

void	ft_sa(t_stack **stack_a, int flag)
{
	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	ft_swap_values(*stack_a, (*stack_a)->next);
	if (flag == 1)
		write(1, "sa\n", 3);
	if (flag == 1)
		ft_bench_update(*stack_a, OP_SA);
}

void	ft_sb(t_stack **stack_b, int flag)
{
	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	ft_swap_values(*stack_b, (*stack_b)->next);
	if (flag == 1)
		write(1, "sb\n", 3);
	if (flag == 1)
		ft_bench_update(*stack_b, OP_SB);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int flag)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	if (flag == 1)
		write(1, "ss\n", 3);
	if (stack_a && *stack_a)
		ft_bench_update(*stack_a, OP_SS);
	else if (stack_b && *stack_b)
		ft_bench_update(*stack_b, OP_SS);
}
