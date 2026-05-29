/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(t_stack *stack, t_stack *to_find, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack == to_find)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*ft_find_biggest(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*biggest;
	int		loop;

	current = stack;
	biggest = current;
	loop = 1;
	while (loop < size)
	{
		current = current->next;
		if (current->index > biggest->index)
			biggest = current;
		loop++;
	}
	return (biggest);
}

t_stack	*ft_find_smallest(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*smallest;
	int		loop;

	current = stack;
	smallest = current;
	loop = 1;
	while (loop < size)
	{
		current = current->next;
		if (current->index < smallest->index)
			smallest = current;
		loop++;
	}
	return (smallest);
}
