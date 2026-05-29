/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	ft_exec_line(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_checker_strcmp(str, "sa\n") == 0)
		ft_sa(stack_a, 0);
	else if (ft_checker_strcmp(str, "sb\n") == 0)
		ft_sb(stack_b, 0);
	else if (ft_checker_strcmp(str, "ss\n") == 0)
		ft_ss(stack_a, stack_b, 0);
	else if (ft_checker_strcmp(str, "pa\n") == 0)
		ft_cpa(stack_a, stack_b);
	else if (ft_checker_strcmp(str, "pb\n") == 0)
		ft_cpb(stack_a, stack_b);
	else if (ft_checker_strcmp(str, "ra\n") == 0)
		ft_ra(stack_a, 0);
	else if (ft_checker_strcmp(str, "rb\n") == 0)
		ft_rb(stack_b, 0);
	else if (ft_checker_strcmp(str, "rr\n") == 0)
		ft_crr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	ft_exec_more(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_exec_line(str, stack_a, stack_b))
		return (1);
	if (ft_checker_strcmp(str, "rra\n") == 0)
		ft_rra(stack_a, 0);
	else if (ft_checker_strcmp(str, "rrb\n") == 0)
		ft_rrb(stack_b, 0);
	else if (ft_checker_strcmp(str, "rrr\n") == 0)
		ft_crrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	ft_read_ops(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (!ft_exec_more(str, stack_a, stack_b))
		{
			free(str);
			return (write(2, "Error\n", 6), 0);
		}
		free(str);
		str = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!ft_checker_init(argc, argv, &stack_a))
		return (1);
	if (!ft_read_ops(&stack_a, &stack_b))
		return (1);
	if (ft_check_order(stack_a, argc - 1) == 1 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a, ft_lst_count(stack_a));
	if (stack_b)
		ft_free_stack(&stack_b, ft_lst_count(stack_b));
	return (0);
}
