#include "push_swap.h"

int	ft_array_handling(int argc, char *argv[], int *arr, t_stack **stack_a)
{
	int	i;

	i = 0;
	
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (ft_check_double(arr, argc - 1) == 0)
	{
		free(arr);
		return (ft_write_err());
	}
	ft_convert_stack(arr, stack_a, argc - 1);
	ft_sort_arr(arr, argc - 1);
	ft_add_order(arr, *stack_a, argc-1);
	return (1);
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
