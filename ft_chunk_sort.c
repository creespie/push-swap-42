#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int i;

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

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk;
	int	start;
	int	i;

	size = ft_lst_count(*stack_a);
	chunk = ft_sqrt(size);
	start = 0;
	while (size > 0)
	{
		i = size;
		while (i > 0)
		{
			if ((*stack_a) -> index >= start && (*stack_a) -> index < start + chunk)
			{	
				ft_pb(stack_a, stack_b);
				size--;
			}
			else
				ft_ra(stack_a, 1);
			i--;
		}
		start += chunk;
	}
	size = ft_lst_count(*stack_b);
	while (size > 0)
	{
		i = ft_position(ft_find_biggest(*stack_b, size), *stack_b, size);
		while (i != 0)
			ft_exec_b(stack_b, &i);
		ft_pa(stack_b, stack_a);
		size--;
	}
}