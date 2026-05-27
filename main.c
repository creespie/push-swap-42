#include "push_swap.h"

/*
** Parses the optional strategy flag from argv.
** Returns the flag index in argv, or -1 if not found.
** Sets *flag to the corresponding FLAG_* constant.
** Defaults to FLAG_ADAPTIVE if no flag is given.
*/
static int	ft_parse_flag(int argc, char *argv[], int *flag)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			return (*flag = FLAG_SIMPLE, i);
		if (ft_strncmp(argv[i], "--medium", 9) == 0)
			return (*flag = FLAG_MEDIUM, i);
		if (ft_strncmp(argv[i], "--complex", 10) == 0)
			return (*flag = FLAG_COMPLEX, i);
		if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			return (*flag = FLAG_ADAPTIVE, i);
		i++;
	}
	*flag = FLAG_ADAPTIVE;
	return (-1);
}


static int	ft_remove_flag(int argc, char *argv[], int flag_idx)
{
	int	i;

	i = flag_idx;
	while (i < argc - 1)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	return (argc - 1);
}


static double	ft_compute_disorder(t_stack *stack_a, int size)
{
	int		*arr;
	t_stack	*cur;
	long	mistakes;
	long	total_pairs;
	int		i;
	int		j;

	if (size <= 1)
		return (0.0);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0.0);
	cur = stack_a;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->index;
		cur = cur->next;
	}
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	free(arr);
	return ((double)mistakes / (double)total_pairs);
}


static void	ft_select_sort(int flag, double disorder,
				t_stack **stack_a, t_stack **stack_b)
{
	if (flag == FLAG_SIMPLE)
		ft_ins_sort(stack_a, stack_b);
	else if (flag == FLAG_MEDIUM)
		ft_chunk_sort(stack_a, stack_b);
	else if (flag == FLAG_COMPLEX)
		ft_sort_everything(stack_a, stack_b);
	else
	{
		if (disorder < 0.2)
			ft_ins_sort(stack_a, stack_b);
		else if (disorder < 0.5)
			ft_chunk_sort(stack_a, stack_b);
		else
			ft_sort_everything(stack_a, stack_b);
	}
}


static void	ft_main_sort(int argc, int flag, double disorder,
				t_stack **stack_a, t_stack **stack_b)
{
	if (argc - 1 <= 4)
		ft_sort_few(stack_a, stack_b, argc - 1);
	else
		ft_select_sort(flag, disorder, stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	int		*arr;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;
	int		flag_idx;
	double	disorder;

	if (argc <= 1)
		return (0);
	flag_idx = ft_parse_flag(argc, argv, &flag);
	if (flag_idx != -1)
		argc = ft_remove_flag(argc, argv, flag_idx);
	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (ft_check_errors(argc, argv) == 0)
		return (0);
	arr = malloc((argc - 1) * sizeof(int));
	if (!arr)
		return (0);
	if (ft_array_handling(argc, argv, arr, &stack_a) == 0)
	{
		free(arr);
		return (0);
	}
	free(arr);
	disorder = ft_compute_disorder(stack_a, argc - 1);
	if (ft_check_order(stack_a, argc - 1) == 0)
		ft_main_sort(argc, flag, disorder, &stack_a, &stack_b);
	ft_free_stack(&stack_a, ft_lst_count(stack_a));
	if (stack_b)
		ft_free_stack(&stack_b, ft_lst_count(stack_b));
	return (0);
}