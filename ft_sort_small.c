#include "push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	t_stack	*one;
	t_stack	*two;

	one = *stack_a;
	two = one->next;
	if (one->index > two->index)
		ft_sa(stack_a, 1);
}

static void	three_append(t_stack **stack)
{
	ft_ra(stack, 1);
	ft_sa(stack, 1);
	ft_rra(stack, 1);
}

/*
** Sorts exactly 3 elements in stack_a in ascending order.
** Cases (top=one, mid=two, bot=three):
**   3 2 1 -> ra + sa  (becomes 1 2 3 via rotate then swap)
**   2 3 1 -> ra       (rotate: 3 1 2 -> no, need 1 2 3: actually ra gives 3 1 2 wrong)
**   Actually re-mapping:
**   one>two && two>three  => [3,2,1]: ra, sa  => [1,3,2] -> [1,2,3]? no [2,3] swap
**   Wait: ra on [3,2,1] => [2,1,3], sa => [1,2,3] ✓
**   one>two && one>three && two<three => [3,1,2]: ra => [1,2,3] ✓
**   one>two && two<three (but one<three) => [2,1,3]: sa => [1,2,3] ✓
**   one<two && one>three => [2,3,1]: three_append: ra,sa,rra
**     ra=>[3,1,2], sa=>[1,3,2], rra=>[2,1,3]... hmm
**   Actually: [2,3,1] -> rra => [1,2,3] ✓  use rra
**   two>three (one<two && one<three) => [1,3,2]: three_append: ra,sa,rra
**     ra=>[3,2,1], sa=>[2,3,1], rra=>[1,2,3] ✓
*/
void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;

	one = *stack_a;
	two = one->next;
	three = two->next;
	if (one->index > two->index && two->index > three->index)
	{
		ft_ra(stack_a, 1);
		ft_sa(stack_a, 1);
	}
	else if (one->index > two->index && one->index > three->index
		&& two->index < three->index)
		ft_ra(stack_a, 1);
	else if (one->index > two->index)
		ft_sa(stack_a, 1);
	else if (one->index > three->index)
		ft_rra(stack_a, 1);
	else if (two->index > three->index)
		three_append(stack_a);
}

/*
** Sorts 4 elements:
** push one to b, sort 3 in a, find spot for b's top in a, push back.
*/
void	ft_sort_few(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pos;

	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
	{
		ft_pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_highest_up(stack_b, ft_lst_count(*stack_b));
		pos = ft_find_spot_a(*stack_b, *stack_a, ft_lst_count(*stack_a));
		while (pos > 0)
		{
			ft_ra(stack_a, 1);
			pos--;
		}
		while (pos < 0)
		{
			ft_rra(stack_a, 1);
			pos++;
		}
		ft_pa(stack_a, stack_b);
		while ((*stack_a)->index != 0)
			ft_rra(stack_a, 1);
	}
}
