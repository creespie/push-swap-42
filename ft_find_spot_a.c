/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_spot_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_ret_a(int i, int size_a)
{
	if (i <= size_a / 2)
		return (i);
	else
		return ((size_a - i) * -1);
}

int	ft_smallest_a(t_stack *stack_a, int size_a)
{
	int	i;

	i = ft_find_index(stack_a, ft_find_smallest(stack_a, size_a), size_a);
	return (ft_find_ret_a(i, size_a));
}

int	ft_find_spot_a(t_stack *current, t_stack *stack_a, int size_a)
{
	t_stack	*n1;
	t_stack	*n2;
	int		i;

	if (ft_find_biggest(stack_a, size_a)->index < current->index)
		return (ft_smallest_a(stack_a, size_a));
	if (ft_find_smallest(stack_a, size_a)->index > current->index)
		return (ft_smallest_a(stack_a, size_a));
	i = 1;
	n1 = stack_a;
	n2 = n1->next;
	while (i < size_a)
	{
		if (n1->index < current->index && n2->index > current->index)
			return (ft_find_ret_a(i, size_a));
		n1 = n2;
		n2 = n1->next;
		i++;
	}
	return (0);
}
