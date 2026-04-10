#include "push_swap.h"

void ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *current;
    int     size_a;
    int     size_b;
    int     i;

    size_a = ft_lst_count(stack_a);
    size_b = ft_lst_count(stack_b);
    write(1, "--- STACK A ---\n", 16);
    current = stack_a;
    i = 0;
    while (i < size_a)
    {
        ft_putnbr(current->content);
        write(1, " (idx:", 6);
        ft_putnbr(current->index);
        write(1, ")\n", 2);
        current = current->next;
        i++;
    }
    write(1, "--- STACK B ---\n", 16);
    current = stack_b;
    i = 0;
    while (i < size_b)
    {
        ft_putnbr(current->content);
        write(1, " (idx:", 6);
        ft_putnbr(current->index);
        write(1, ")\n", 2);
        current = current->next;
        i++;
    }
    write(1, "---------------\n", 16);
}

void	b_to_a_append(t_stack **stack_a, t_stack **stack_b)
{
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a, 1);
}

void	ft_right_rotation(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_b;
	int	number;

	top_b = *stack_b;
	number = ft_find_spot_a(top_b, *stack_a, ft_lst_count(*stack_a), 0);
	while (number > 0)
	{
		ft_ra(stack_a, 1);
		number--;
	}
		while (number < 0)
	{
		ft_rra(stack_a, 1);
		number++;
	}
	ft_pa(stack_a, stack_b);
}

void	ft_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_b;
	t_stack	*top_a;
	t_stack	*bottom_a;

	while (ft_lst_count(*stack_b) > 0)
	{
		top_b = *stack_b;
		top_a = *stack_a;
		bottom_a = top_a->prev;
		if (top_b->index > top_a->index && top_b->index > bottom_a->index)
		{
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a, 1);
		}
		else if (top_b->index > top_a->index && top_b->index < bottom_a->index)
			ft_right_rotation(stack_a, stack_b);
		else if (top_b->index < top_a->index && top_b->index > bottom_a->index)
			ft_pa(stack_a, stack_b);
		else if (top_b->index < top_a->index && top_b->index < bottom_a->index)
			ft_right_rotation(stack_a, stack_b);
	}
}

void	ft_sort_everything(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	if ((*stack_b)->index > (*stack_b)->prev->index)
		ft_rb(stack_b, 1);
	while (ft_lst_count(*stack_a) > 3)
	{
		best = ft_fastest(*stack_a, *stack_b, ft_lst_count(*stack_a), 0);
		ft_execute(stack_a, stack_b, best, ft_lst_count(*stack_a));
	}
	ft_highest_up(stack_b, ft_lst_count(*stack_b), 0);
	ft_sort_three(stack_a);
	ft_b_to_a(stack_a, stack_b);
	best = *stack_a;
	while ((*stack_a)->index > 0)
		ft_rra(stack_a, 1);
	ft_print_stacks(*stack_a, *stack_b);
}
