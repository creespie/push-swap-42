#include "push_swap.h"

void	ft_convert_stack(int *arr, t_stack **stack_a, int size)
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

void	ft_execute(t_stack **stack_a, t_stack **stack_b, t_stack *fastest, int size)
{
	int	position;
	int	spot;

	position = ft_position(fastest, *stack_a, size);
	spot = ft_find_spot(fastest, *stack_b, ft_lst_count(*stack_b), 0);
	while (position > 0 && spot > 0)
	{
		ft_rr(stack_a, stack_b);
		position--;
		spot--;
	}
	while (position < 0 && spot < 0)
	{
		ft_rrr(stack_a, stack_b);
		position++;
		spot++;
	}
	while (position > 0)
	{
		ft_ra(stack_a, 1);
		position--;
	}
	while (spot > 0)
	{
		ft_rb(stack_b, 1);
		spot--;
	}
	while (position < 0)
	{
		ft_rra(stack_a, 1);
		position++;
	}
	while (spot < 0)
	{
		ft_rrb(stack_b, 1);
		spot++;
	}
	ft_pb(stack_a, stack_b);
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
		ft_rra(stack, 1);
		ft_sa(stack, 1);
	}
	else if (one->index > two->index && one->index > three->index && two->index < three->index )
		ft_ra(stack, 1);
	else if (one->index > two->index)
		ft_sa(stack);
	else if (one->index > three->index)
		ft_rra(stack, 1);
	else if (two->index > three->index)
	{
		ft_ra(stack, 1);
		ft_sa(stack);
		ft_rra(stack, 1);
	}
}

void	ft_sort_two(t_stack **stack)
{
	t_stack *one;
	t_stack	*two;

	one = *stack;
	two = one->next;
	if (one->index > two->index)
		ft_ra(stack, 1);
}

int	ft_check_order(t_stack *stack, int size)
{
	int	i;
	t_stack	*check;
	
	check = stack;
	i = 0;
	while (i < size)
	{
		if (check->index == i)
		{
			check = check->next;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

void	ft_free_stack(t_stack **stack, int size)
{
	int	i;
	t_stack	*to_free;
	t_stack	*temp;

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

void	ft_highest_up(t_stack **stack_b, int size, 	int	i, int	position)
{
	int	highest_index;
	t_stack	*current;

	current = *stack_b;
	highest_index = current->index;
	while (i < size)
	{
		i++;
		current = current->next;
		if (current->index > highest_index)
		{
			highest_index = current->index;
			position = i;
		}
	}
	while (position <= size / 2 && position > 0)
	ft_highest_app(stack_b, &position, 0);
	while (position > size / 2 && position <= size)
	ft_highest_app(stack_b, &position, 1);
}

void	ft_highest_app(t_stack **stack_b, int *position, int flag)
{
	if (flag == 0)
	{
		ft_rb(stack_b, 1);
		(*position)--;
	}
	else if (flag == 1)
	{
		ft_rrb(stack_b, 1);
		(*position)++;
	}
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
			ft_sa(stack_a, 1);
			ft_ra(stack_a, 1);
		}
		else if (top_b->index < top_a->index && top_b->index < bottom_a->index)
		{
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a, 1);
		}
		else if (top_b->index < top_a->index && top_b->index > bottom_a->index)
			ft_pa(stack_a, stack_b);
		else
			ft_rra(stack_a, 1);
	}
}

void	ft_sort_everything(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	while (ft_lst_count(*stack_a) > 3)
	{
		best = ft_fastest(*stack_a, *stack_b, ft_lst_count(*stack_a), 0);
		ft_execute(stack_a, stack_b, best, ft_lst_count(*stack_a));
	}
	ft_highest_up(stack_b, ft_lst_count(*stack_b), 0, 0);
	ft_sort_three(stack_a);
	ft_rra(stack_a, 1);
	ft_b_to_a(stack_a, stack_b);
	best = *stack_a;
	while (best->index > 0)
		{
		best = *stack_a;
		ft_rra(stack_a, 1);
		}
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

void ft_sort_few(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*best;

	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
	{
		ft_pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_rra(stack_a, 1);
		ft_b_to_a(stack_a, stack_b);
		best = *stack_a;
		while (best->index > 0)
		{
			best = *stack_a;
			ft_rra(stack_a, 1);
		}
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*arr;
	t_stack *stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
		{
			write (2, "Error\n", 6);
			return(0);
		}
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				write (2, "Error\n", 6);
				return(0);
			}
			j++;
		}
		i++;
	}
	i = 0;
	arr = malloc((argc - 1) * sizeof(int));
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (ft_check_double(arr, argc - 1) == 0)
	{
		write (2, "Error\n", 6);
		free(arr);
		return(0);
	}
	ft_convert_stack(arr, &stack_a, argc - 1);
	ft_sort_arr(arr, argc - 1);
	ft_add_order(arr, stack_a, argc-1);
	if (ft_check_order(stack_a, argc - 1) == 1)
	{}
	else
	{
		if (argc - 1 <= 4)
			ft_sort_few(&stack_a, &stack_b, argc - 1);
		else
			ft_sort_everything(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a, argc - 1);
	free(arr);
	return (0);
}