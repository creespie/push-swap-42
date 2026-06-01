/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_pop_top(t_stack **stack)
{
	t_stack	*node;
	t_stack	*next;
	t_stack	*prev;

	node = *stack;
	next = node->next;
	prev = node->prev;
	next->prev = prev;
	prev->next = next;
	if (node->next == node)
		*stack = NULL;
	else
		*stack = next;
	return (node);
}

static void	ft_push_top(t_stack **stack, t_stack *node)
{
	t_stack	*next;
	t_stack	*prev;

	if (!*stack)
	{
		node->next = node;
		node->prev = node;
		*stack = node;
		return ;
	}
	next = *stack;
	prev = next->prev;
	next->prev = node;
	node->next = next;
	prev->next = node;
	node->prev = prev;
	*stack = node;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!*stack_b)
		return ;
	node = ft_pop_top(stack_b);
	ft_push_top(stack_a, node);
	write(1, "pa\n", 3);
	ft_bench_update(*stack_a, OP_PA);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!*stack_a)
		return ;
	node = ft_pop_top(stack_a);
	ft_push_top(stack_b, node);
	write(1, "pb\n", 3);
	ft_bench_update(*stack_b, OP_PB);
}
