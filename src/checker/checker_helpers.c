/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_checker_pop(t_stack **stack)
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

static void	ft_checker_push(t_stack **stack, t_stack *node)
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

void	ft_cpa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!*stack_b)
		return ;
	node = ft_checker_pop(stack_b);
	ft_checker_push(stack_a, node);
	ft_bench_update(*stack_a, OP_PA);
}

void	ft_cpb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!*stack_a)
		return ;
	node = ft_checker_pop(stack_a);
	ft_checker_push(stack_b, node);
	ft_bench_update(*stack_b, OP_PB);
}
