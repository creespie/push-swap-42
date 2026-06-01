/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **stack_a, int flag)
{
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	if (flag == 1)
		write(1, "rra\n", 4);
	if (flag == 1)
		ft_bench_update(*stack_a, OP_RRA);
}

void	ft_rrb(t_stack **stack_b, int flag)
{
	if (!stack_b || !*stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
	if (flag == 1)
		write(1, "rrb\n", 4);
	if (flag == 1)
		ft_bench_update(*stack_b, OP_RRB);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	write(1, "rrr\n", 4);
	if (stack_a && *stack_a)
		ft_bench_update(*stack_a, OP_RRR);
	else if (stack_b && *stack_b)
		ft_bench_update(*stack_b, OP_RRR);
}
