/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_right_rotation(t_stack **stack_a, t_stack **stack_b)
{
	int	number;

	number = ft_find_spot_a(*stack_b, *stack_a, ft_lst_count(*stack_a));
	while (number > 0)
	{
		ft_ra(stack_a, 1);
		number--;
	}
	while (number < 0)
	{
		ft_rra(stack_a, 1);
		number++;
	}
	ft_pa(stack_a, stack_b);
}

static void	ft_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_b;
	t_stack	*top_a;
	t_stack	*bot_a;

	while (ft_lst_count(*stack_b) > 0)
	{
		top_b = *stack_b;
		top_a = *stack_a;
		bot_a = top_a->prev;
		if (top_b->index > top_a->index && top_b->index > bot_a->index)
		{
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a, 1);
		}
		else if (top_b->index > top_a->index && top_b->index < bot_a->index)
			ft_right_rotation(stack_a, stack_b);
		else if (top_b->index < top_a->index && top_b->index > bot_a->index)
			ft_pa(stack_a, stack_b);
		else
			ft_right_rotation(stack_a, stack_b);
	}
}

void	ft_sort_everything(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best;

	if (ft_lst_count(*stack_a) >= 5)
	{
		ft_pb(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		if ((*stack_b)->index < (*stack_b)->next->index)
			ft_rb(stack_b, 1);
		while (ft_lst_count(*stack_a) > 3)
		{
			best = ft_fastest(*stack_a, *stack_b, ft_lst_count(*stack_a));
			ft_execute(stack_a, stack_b, best, ft_lst_count(*stack_a));
		}
		ft_sort_three(stack_a);
		ft_highest_up(stack_b, ft_lst_count(*stack_b));
		ft_b_to_a(stack_a, stack_b);
		while ((*stack_a)->index != 0)
			ft_rra(stack_a, 1);
	}
	else
		ft_sort_few(stack_a, stack_b, ft_lst_count(*stack_a));
}
