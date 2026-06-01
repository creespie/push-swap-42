/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_position(t_stack *current, t_stack *stack_a, int size)
{
	t_stack	*checking;
	int		i;

	i = 0;
	checking = stack_a;
	while (i < size)
	{
		if (checking == current)
		{
			if (i <= size / 2)
				return (i);
			else
				return ((size - i) * -1);
		}
		checking = checking->next;
		i++;
	}
	return (0);
}
