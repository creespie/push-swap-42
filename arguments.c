#include "push_swap.h"

int	ft_convert_stack(int *arr, t_stack **stack_a, int size)
{
	int	i;
	t_stack *new;

	i = 0;
	while (size > 0)
	{
		new = ft_lstnew_adapt(arr[i]);
		if (*stack_a == NULL)
			*stack_a = new;
		else
			ft_lstadd_back_adapt(stack_a, new);
		i++;
		size--;
	}
	ft_close_circle(*stack_a);
	return (i);
}

void	ft_close_circle(t_stack *stack_a)
{
	t_stack	*first;
	t_stack	*last;

	first = stack_a;
	last = ft_lstlast(stack_a);
	first->prev = last;
	last->next = first;
}

void	ft_sort_arr(int *arr, int size)
{
	int	i;
	int	y;
	int	temp;

	i = 0;
	temp = 0;
	while (i < size)
	{
		y = i;
		while (y < size)
		{
			if (arr[y] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[y];
				arr[y] = temp;
			}
			y++;
		}
		i++;
	}
}

void	ft_add_order(int *arr, t_stack *stack_a, int size)
{
	int	i;
	t_stack	*temp;

	temp = stack_a;
	if (stack_a == NULL)
		return ;
	while (size > 0)
	{
		i = 0;
		while (arr[i] != temp->content)
			i++;
		temp->index = i;
		temp = temp->next;
		size--;
	}
}

int	ft_find_spot(t_stack *current, t_stack *stack_b, int size_b, int i)
{
	t_stack	*n1;
	t_stack *n2;

	n1 = stack_b;
	n2 = n1->prev;
	if (n2->index < current->index && n1->index > current->index)
		return (0);
	n2 = n1;
	while (i < size_b)
	{
		n1 = n2;
		n2 = n1->next;
		if (n1->index < current->index && n2->index > current->index)
		{
			if (i <= size_b / 2)
				return (i);
			else
				return ((size_b - i) * -1);
		}
		i++;
	}
	return ;
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
	return;
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
			total = pos_2;
		else
			total = spot_2;
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

t_stack	*ft_fastest(t_stack *stack_a, t_stack *stack_b, int size, int position)
{
	int	i;
	int	spot;
	t_stack *current;
	t_stack	*next;

	i = 0;
	current = stack_a;
	next = stack_a;
	spot = ft_find_spot(current, stack_b, ft_lst_count(stack_b), 0);
	while (i < size)
	{
		next = next->next;
		if (ft_compare(position, spot, ft_position(next, stack_a, size),
		 	ft_find_spot(next, stack_b, ft_lst_count(stack_b), 0)) == 1)
		{
			position = ft_position(next, stack_a, size);
			spot = ft_find_spot(next, stack_b, ft_lst_count(stack_b), 0);
			current = next;
		}
		i++;
	}
	return (current);
}

void	ft_execute(t_stack *stack_a, t_stack *stack_b, t_stack *fastest, int size)
{
	int	position;
	int	spot;

	position = ft_position(fastest, stack_a, size);
	spot = ft_find_spot(fastest, stack_b, ft_lst_count(stack_b), 0);
	while (position > 0 && spot > 0)
	{
		ft_rr(&stack_a, &stack_b);
		position--;
		spot--;
	}
	while (position < 0 && spot < 0)
	{
		ft_rrr(&stack_a, &stack_b);
		position++;
		spot++;
	}
	while (position > 0)
	{
		ft_ra(&stack_a, 1);
		position--;
	}
	while (spot > 0)
	{
		ft_rb(&stack_a, 1);
		spot--;
	}
	while (position < 0)
	{
		ft_rra(&stack_a, 1);
		position++;
	}
	while (spot < 0)
	{
		ft_rrb(&stack_a, 1);
		spot++;
	}
	ft_pa(&stack_a, &stack_b);
}

void	ft_sort_three(t_stack **stack)
{
	t_stack	*one;
	t_stack	*two;
	t_stack *three;

	one = *stack;
	two = one->next;
	three = two->next;
	if (one->index > two->index && two->index > three->index)
	{
		ft_ra(stack, 1);
		ft_ra(stack, 1);
	}
	if (one->index > two->index && one->index > three->index && two->index < three->index )
		ft_ra(stack, 1);
	if (one->index > two->index)
		ft_sa(stack);
	if (one->index > three->index)
		ft_rra(stack, 1);
	if (two->index > three->index)
	{
		ft_ra(stack, 1);
		ft_sa(stack);
		ft_rra(stack, 1);
	}
}