/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	ft_exec_b(t_stack **stack_b, int *spot)
{
	if (*spot > 0)
	{
		ft_rb(stack_b, 1);
		(*spot)--;
	}
	else
	{
		ft_rrb(stack_b, 1);
		(*spot)++;
	}
}

static void	ft_push_chunk(t_stack **stack_a, t_stack **stack_b,
		int *size, int start)
{
	int	chunk;
	int	i;

	chunk = ft_sqrt(ft_lst_count(*stack_a) + ft_lst_count(*stack_b));
	i = *size;
	while (i > 0)
	{
		if ((*stack_a)->index >= start && (*stack_a)->index < start + chunk)
		{
			ft_pb(stack_a, stack_b);
			(*size)--;
		}
		else
			ft_ra(stack_a, 1);
		i--;
	}
}

static void	ft_pull_biggest(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pos;

	while (size > 0)
	{
		pos = ft_position(ft_find_biggest(*stack_b, size), *stack_b, size);
		while (pos != 0)
			ft_exec_b(stack_b, &pos);
		ft_pa(stack_a, stack_b);
		size--;
	}
}

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	start;
	int	chunk;

	size = ft_lst_count(*stack_a);
	chunk = ft_sqrt(size);
	start = 0;
	while (size > 0)
	{
		ft_push_chunk(stack_a, stack_b, &size, start);
		start += chunk;
	}
	ft_pull_biggest(stack_a, stack_b, ft_lst_count(*stack_b));
}
