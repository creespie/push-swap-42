/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_write_err(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	ft_check_double(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_errors(int argc, char *argv[])
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (ft_write_err());
		len = j;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_write_err());
			j++;
		}
		if (j - len > 10)
			return (ft_write_err());
		i++;
	}
	return (1);
}

int	ft_check_order(t_stack *stack, int size)
{
	t_stack	*check;
	int		i;

	check = stack;
	i = 0;
	while (i < size)
	{
		if (check->index != i)
			return (0);
		check = check->next;
		i++;
	}
	return (1);
}
