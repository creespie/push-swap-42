/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_spot_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_ret_b(int i, int size_b)
{
	if (i <= size_b / 2)
		return (i);
	else
		return ((size_b - i) * -1);
}

static int	ft_smallest_b(t_stack *stack_b, int size_b)
{
	int	i;

	i = ft_find_index(stack_b, ft_find_biggest(stack_b, size_b), size_b);
	return (ft_find_ret_b(i, size_b));
}

int	ft_find_spot(t_stack *current, t_stack *stack_b, int size_b)
{
	t_stack	*n1;
	t_stack	*n2;
	int		i;

	if (!stack_b || size_b == 0)
		return (0);
	if (ft_find_biggest(stack_b, size_b)->index < current->index)
		return (ft_smallest_b(stack_b, size_b));
	if (ft_find_smallest(stack_b, size_b)->index > current->index)
		return (ft_smallest_b(stack_b, size_b));
	i = 1;
	n1 = stack_b;
	n2 = n1->next;
	while (i <= size_b)
	{
		if (n1->index > current->index && n2->index < current->index)
			return (ft_find_ret_b(i, size_b));
		n1 = n2;
		n2 = n1->next;
		i++;
	}
	return (0);
}
