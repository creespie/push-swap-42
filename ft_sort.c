/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_append(t_stack **stack)
{
	ft_ra(stack, 1);
	ft_sa(stack, 1);
	ft_rra(stack, 1);
}

void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;

	one = *stack_a;
	two = one->next;
	three = two->next;
	if (one->index > two->index && two->index > three->index)
	{
		ft_ra(stack_a, 1);
		ft_sa(stack_a, 1);
	}
	else if (one->index > two->index && one->index > three->index
		&& two->index < three->index)
		ft_ra(stack_a, 1);
	else if (one->index > two->index)
		ft_sa(stack_a, 1);
	else if (one->index > three->index)
		ft_rra(stack_a, 1);
	else if (two->index > three->index)
		three_append(stack_a);
}

static void	ft_rotate_to_pos(t_stack **stack_a, int pos)
{
	while (pos > 0)
	{
		ft_ra(stack_a, 1);
		pos--;
	}
	while (pos < 0)
	{
		ft_rra(stack_a, 1);
		pos++;
	}
}

static void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;

	ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_highest_up(stack_b, ft_lst_count(*stack_b));
	pos = ft_find_spot_a(*stack_b, *stack_a, ft_lst_count(*stack_a));
	ft_rotate_to_pos(stack_a, pos);
	ft_pa(stack_a, stack_b);
	while ((*stack_a)->index != 0)
		ft_rra(stack_a, 1);
}

void	ft_sort_few(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
}
