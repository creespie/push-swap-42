/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **stack_a, int flag)
{
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	if (flag == 1)
		write(1, "ra\n", 3);
	if (flag == 1)
		ft_bench_update(*stack_a, OP_RA);
}

void	ft_rb(t_stack **stack_b, int flag)
{
	if (!stack_b || !*stack_b)
		return ;
	*stack_b = (*stack_b)->next;
	if (flag == 1)
		write(1, "rb\n", 3);
	if (flag == 1)
		ft_bench_update(*stack_b, OP_RB);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	write(1, "rr\n", 3);
	if (stack_a && *stack_a)
		ft_bench_update(*stack_a, OP_RR);
	else if (stack_b && *stack_b)
		ft_bench_update(*stack_b, OP_RR);
}
