#include "push_swap.h"

void	ft_sa(t_stack **stack_a, int flag)
{
	t_stack	*n1;
	t_stack	*n2;
	int		temp;

	if (*stack_a == NULL)
		return ;
	n1 = *stack_a;
	if (n1 -> next == NULL)
		return ;
	temp = n1->content;
	n1->content = n2->content;
	n2->content = temp;
	temp = n1->index;
	n1->index = n2->index;
	n2->index = temp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b, int flag)
{
	t_stack	*n1;
	t_stack	*n2;
	int		temp;

	if (*stack_b == NULL)
		return ;
	n1 = *stack_b;
	if (n1 -> next == NULL)
		return ;
	temp = n1->content;
	n1->content = n2->content;
	n2->content = temp;
	temp = n1->index;
	n1->index = n2->index;
	n2->index = temp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	write(1, "ss\n", 3);
}
