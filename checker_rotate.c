/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_crrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (stack_a && *stack_a)
		ft_bench_update(*stack_a, OP_RRR);
	else if (stack_b && *stack_b)
		ft_bench_update(*stack_b, OP_RRR);
}

void	ft_crr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (stack_a && *stack_a)
		ft_bench_update(*stack_a, OP_RR);
	else if (stack_b && *stack_b)
		ft_bench_update(*stack_b, OP_RR);
}
