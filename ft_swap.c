#include "push_swap.h"

void	ft_sa(t_stack *stack_a)
{
	t_stack	*n1;
	t_stack	*n2;
	int		temp;

	if (stack_a == NULL)
		return ;
	n1 = stack_a;
	if (n1 -> next == NULL)
		return ;
	temp = n1->content;
	n1->content = n2->content;
	n2->content = temp;
	temp = n1->index;
	n1->index = n2->index;
	n2->index = temp;
}

void	ft_sb(t_stack *stack_b)
{
	t_stack	*n1;
	t_stack	*n2;
	int		temp;

	if (stack_b == NULL)
		return ;
	n1 = stack_b;
	if (n1 -> next == NULL)
		return ;
	temp = n1->content;
	n1->content = n2->content;
	n2->content = temp;
	temp = n1->index;
	n1->index = n2->index;
	n2->index = temp;
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
