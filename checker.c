#include "push_swap.h"
#include "get_next_line.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((s1[i] - s2[i]));
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*arr;
	char	*str;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!ft_check_errors(argc, argv))
		return (write(2, "Error\n", 6), 1);
	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (0);
	if (!ft_array_handling(argc, argv, arr, &stack_a))
		return (free(arr), 0);
	free(arr);
	str = get_next_line(0);
	while (str != NULL)
	{
		if (ft_strcmp(str, "sa\n") == 0)
			ft_sa(stack_a, 0);
		else if (ft_strcmp(str, "sb\n") == 0)
			ft_sb(stack_b, 0);
		else if (ft_strcmp(str, "ss\n") == 0)
			ft_ss(stack_a, stack_b, 0);		
		else if (ft_strcmp(str, "pa\n") == 0)
			ft_cpa(stack_a, stack_b);		
		else if (ft_strcmp(str, "pb\n") == 0)
			ft_cpb(stack_a, stack_b);		
		else if (ft_strcmp(str, "ra\n") == 0)
			ft_ra(stack_a, 0);		
		else if (ft_strcmp(str, "rb\n") == 0)
			ft_rb(stack_b, 0);
		else if (ft_strcmp(str, "rr\n") == 0)
			ft_crr(stack_a, stack_b);
		else if (ft_strcmp(str, "rra\n") == 0)
			ft_rra(stack_a, 0);
		else if (ft_strcmp(str, "rrb\n") == 0)
			ft_rrb(stack_b, 0);
		else if (ft_strcmp(str, "rrr\n") == 0)
			ft_crrr(stack_a, stack_b);
		else
			{
				free(str);
				return (write(2, "Error\n", 6), 1);
			}
		free(str);
		str = get_next_line(0);
	}
	if (ft_check_order(stack_a, argc - 1) == 1 && !stack_b)
		return (write(1, "OK\n", 3));
	else
		return (write(1, "KO\n", 3));
}