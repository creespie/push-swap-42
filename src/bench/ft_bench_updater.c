/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_updater.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_update_swap(t_bench *b, t_op op)
{
	if (op == OP_SA)
		b->sa++;
	else if (op == OP_SB)
		b->sb++;
	else if (op == OP_SS)
		b->ss++;
}

static void	ft_update_push(t_bench *b, t_op op)
{
	if (op == OP_PA)
		b->pa++;
	else if (op == OP_PB)
		b->pb++;
}

static void	ft_update_rotate(t_bench *b, t_op op)
{
	if (op == OP_RA)
		b->ra++;
	else if (op == OP_RB)
		b->rb++;
	else if (op == OP_RR)
		b->rr++;
	else if (op == OP_RRA)
		b->rra++;
	else if (op == OP_RRB)
		b->rrb++;
	else if (op == OP_RRR)
		b->rrr++;
}

void	ft_bench_update(t_stack *stack, t_op op)
{
	t_bench	*b;

	if (!stack)
		return ;
	b = stack->bench;
	if (!b || !b->enabled)
		return ;
	b->total_ops++;
	ft_update_swap(b, op);
	ft_update_push(b, op);
	ft_update_rotate(b, op);
}
