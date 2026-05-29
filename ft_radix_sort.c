/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_bits(int size)
{
	int	bits;
	int	max;

	bits = 0;
	max = size - 1;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

static void	ft_push_back_all(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	bits;
	int	bit;
	int	size;
	int	i;

	size = ft_lst_count(*stack_a);
	bits = ft_max_bits(size);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*stack_a)->index >> bit) & 1)
				ft_ra(stack_a, 1);
			else
				ft_pb(stack_a, stack_b);
			i++;
		}
		ft_push_back_all(stack_a, stack_b);
		bit++;
	}
}
