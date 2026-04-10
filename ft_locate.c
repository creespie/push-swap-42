#include "push_swap.h"

int	ft_find_index(t_stack *stack, t_stack *to_find, int size)
{
	int	i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (i < size)
	{
		if (current == to_find)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}

t_stack	*ft_find_biggest(t_stack *stack, int size)
{
	int	loop;
	t_stack	*current;
	t_stack	*biggest;

	loop = 1;
	current = stack;
	biggest = current;
	while(loop < size)
	{
		current = current->next;
		if (biggest->index < current->index)
			biggest = current;
		loop++;
	}
	return (biggest);
}

t_stack	*ft_find_smallest(t_stack *stack, int size)
{
	int	loop;
	t_stack	*current;
	t_stack	*smallest;

	loop = 1;
	current = stack;
	smallest = current;
	while(loop < size)
	{
		current = current->next;
		if (smallest->index > current->index)
			smallest = current;
		loop++;
	}
	return (smallest);
}

int	ft_find_spot(t_stack *current, t_stack *stack_b, int size_b, int i)
{
	t_stack	*n1;
	t_stack *n2;

	n1 = stack_b;
	n2 = n1->prev;
	if (!stack_b || size_b == 0)
        return (0);
	if (ft_find_biggest(stack_b, size_b)->index < current->index)
	{
		i = ft_find_index(stack_b, ft_find_biggest(stack_b, size_b), size_b);
		if (i <= size_b / 2)
			return (i);
		else
			return ((size_b - i) * -1);
	}
	if (ft_find_smallest(stack_b, size_b)->index > current->index)
	{
		i = ft_find_index(stack_b, ft_find_biggest(stack_b, size_b), size_b);
		if (i <= size_b / 2)
			return (i);
		else
			return ((size_b - i) * -1);
	}
	n2 = n1;
	while (i <= size_b)
	{
		n1 = n2;
		n2 = n1->next;
		if (n1->index > current->index && n2->index < current->index)
		{
			if (i <= size_b / 2)
				return (i);
			else
				return ((size_b - i) * -1);
		}
		i++;
	}
	return (0);
}

int	ft_find_spot_a(t_stack *current, t_stack *stack_a, int size_a, int i)
{
	t_stack	*n1;
	t_stack *n2;

	n1 = stack_a;
	n2 = n1;
	if (ft_find_biggest(stack_a, size_a)->index < current->index)
	{
		i = ft_find_index(stack_a, ft_find_smallest(stack_a, size_a), size_a);
		if (i <= size_a / 2)
			return (i);
		else
			return ((size_a - i) * -1);
	}
	if (ft_find_smallest(stack_a, size_a)->index > current->index)
	{
		i = ft_find_index(stack_a, ft_find_smallest(stack_a, size_a), size_a);
		if (i <= size_a / 2)
			return (i);
		else
			return ((size_a - i) * -1);
	}
	i = 1;
	while (i < size_a)
	{
		n1 = n2;
		n2 = n1->next;
		if (n1->index < current->index && n2->index > current->index)
		{
			if (i <= size_a / 2)
				return (i);
			else
				return ((size_a - i) * -1);
		}
		i++;
	}
	return (0);
}

int	ft_position(t_stack *current, t_stack *stack_a, int size)
{
	int	i;
	t_stack	*checking;

	i = 0;
	checking = stack_a;
	checking = checking->prev;
	while (i < size)
	{
		checking = checking->next;
		if (checking == current)
		{
			if (i <= size / 2)
				return (i);
			else
				return ((size - i) * -1);
		}
		i++;
	}
	return (0);
}

int	ft_compare(int	pos, int spot, int	pos_2, int spot_2)
{
	int	total;
	int	total_2;

	if ((pos > 0 && spot > 0)|| (pos < 0 && spot < 0))
	{
		if ((pos > 0 && pos > spot) || (pos < 0 && pos < spot))
			total = pos;
		else
			total = spot;
	}
	else
		total = (spot * -1) + pos;
	if ((pos_2 > 0 && spot_2 > 0)|| (pos_2 < 0 && spot_2 < 0))
	{
		if ((pos_2 > 0 && pos_2 > spot_2) || (pos_2 < 0 && pos_2 < spot_2))
			total_2 = pos_2;
		else
			total_2 = spot_2;
	}
	else
		total_2 = (spot_2 * -1) + pos_2;
	if (total < 0)
		total *= -1;
	if (total_2 < 0)
		total_2 *= -1;
	if (total_2 < total)
		return 1;
	return 0;
}
