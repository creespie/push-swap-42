#include "push_swap.h"

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

int	ft_write_err()
{
	write (2, "Error\n", 6);
	return(0);
}

int	ft_check_errors(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
			return(ft_write_err());
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (ft_write_err());
			j++;
		}
		i++;
	}
	return (1);
}
