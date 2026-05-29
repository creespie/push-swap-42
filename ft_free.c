/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack, int size)
{
	t_stack	*to_free;
	t_stack	*temp;
	int		i;

	if (!stack || !*stack)
		return ;
	i = 0;
	to_free = *stack;
	while (i < size)
	{
		temp = to_free->next;
		free(to_free);
		to_free = temp;
		i++;
	}
	*stack = NULL;
}

void	ft_highest_up(t_stack **stack_b, int size)
{
	int	i;

	if (!*stack_b || size <= 1)
		return ;
	if (ft_find_biggest(*stack_b, size) == *stack_b)
		return ;
	i = ft_find_index(*stack_b, ft_find_biggest(*stack_b, size), size);
	while (i > 0 && i <= size / 2)
	{
		ft_rb(stack_b, 1);
		i--;
	}
	while (i > size / 2 && i < size)
	{
		ft_rrb(stack_b, 1);
		i++;
	}
}
