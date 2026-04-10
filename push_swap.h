#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "libft/libft.h"

typedef struct		s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a, int flag);
void	ft_rb(t_stack **stack_b, int flag);
void	ft_rr(t_stack **stack_b, t_stack **stack_a);
void	ft_rra(t_stack **stack_a, int flag);
void	ft_rrb(t_stack **stack_b, int flag);
void	ft_rrr(t_stack **stack_b, t_stack **stack_a);
void	ft_sa(t_stack **stack_a, int flag);
void	ft_sb(t_stack **stack_b, int flag);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_lstnew_adapt(int content);
void ft_lstadd_back_adapt(t_stack **lst, t_stack *new);
int	ft_lst_count(t_stack *stack);
void	ft_convert_stack(int *arr, t_stack **stack_a, int size);
void	ft_close_circle(t_stack *stack_a);
void	ft_sort_arr(int *arr, int size);
void	ft_add_order(int *arr, t_stack *stack_a, int size);
int	ft_find_spot(t_stack *current, t_stack *stack_b, int size_b, int i);
int	ft_position(t_stack *current, t_stack *stack_a, int size);
int	ft_compare(int	pos, int spot, int	pos_2, int spot_2);
t_stack	*ft_fastest(t_stack *stack_a, t_stack *stack_b, int size, int position);
void	ft_execute(t_stack **stack_a, t_stack **stack_b, t_stack *fastest, int size);
void	ft_sort_three(t_stack **stack);
void	ft_sort_two(t_stack **stack);
int	ft_check_order(t_stack *stack, int size);
void	ft_free_stack(t_stack **stack, int size);
void	ft_highest_up(t_stack **stack_b, int size, 	int	i);
void	ft_highest_app(t_stack **stack_b, int *position, int flag);
void	ft_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_everything(t_stack **stack_a, t_stack **stack_b);
int	ft_check_double(int *arr, int size);
void ft_sort_few(t_stack **stack_a, t_stack **stack_b, int size);
t_stack *ft_lstlast_adapt(t_stack *lst);
int	ft_find_spot_a(t_stack *current, t_stack *stack_a, int size_a, int i);
int	ft_find_index(t_stack *stack, t_stack *to_find, int size);
t_stack	*ft_find_biggest(t_stack *stack, int size);
t_stack	*ft_find_smallest(t_stack *stack, int size);
//void ft_print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif