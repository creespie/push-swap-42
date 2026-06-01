/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define FLAG_SIMPLE 1
# define FLAG_MEDIUM 2
# define FLAG_COMPLEX 3
# define FLAG_ADAPTIVE 4

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_bench
{
	double	disorder;
	int		strategy;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		enabled;
}	t_bench;

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
	t_bench			*bench;
}	t_stack;

typedef struct s_app
{
	t_stack	*a;
	t_stack	*b;
	int		argc;
	int		strategy;
	double	disorder;
	t_bench	bench;
}	t_app;

typedef struct s_disorder
{
	int		i;
	int		j;
	long	mistakes;
	long	total;
}	t_disorder;

t_stack	*ft_lstnew_ps(int content);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast_ps(t_stack *lst);
int		ft_lst_count(t_stack *stack);
void	ft_close_circle(t_stack *stack);
int		ft_check_errors(int argc, char *argv[]);
int		ft_check_double(int *arr, int size);
int		ft_write_err(void);
int		ft_check_order(t_stack *stack, int size);
void	ft_sort_arr(int *arr, int size);
void	ft_add_order(int *arr, t_stack *stack_a, int size);
int		ft_array_handling(int argc, char *argv[], int *arr, t_stack **stack_a);
int		ft_find_index(t_stack *stack, t_stack *to_find, int size);
t_stack	*ft_find_biggest(t_stack *stack, int size);
t_stack	*ft_find_smallest(t_stack *stack, int size);
int		ft_position(t_stack *current, t_stack *stack_a, int size);
int		ft_find_spot(t_stack *current, t_stack *stack_b, int size_b);
int		ft_find_spot_a(t_stack *current, t_stack *stack_a, int size_a);
int		ft_compare(int pos, int spot, int pos_2, int spot_2);
t_stack	*ft_fastest(t_stack *stack_a, t_stack *stack_b, int size);
void	ft_execute(t_stack **stack_a, t_stack **stack_b,
			t_stack *fastest, int size);
void	ft_free_stack(t_stack **stack, int size);
void	ft_highest_up(t_stack **stack_b, int size);
void	ft_sa(t_stack **stack_a, int flag);
void	ft_sb(t_stack **stack_b, int flag);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int flag);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a, int flag);
void	ft_rb(t_stack **stack_b, int flag);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a, int flag);
void	ft_rrb(t_stack **stack_b, int flag);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_cpa(t_stack **stack_a, t_stack **stack_b);
void	ft_cpb(t_stack **stack_a, t_stack **stack_b);
void	ft_crr(t_stack **stack_a, t_stack **stack_b);
void	ft_crrr(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_two(t_stack **stack_a);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort_few(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_sort_everything(t_stack **stack_a, t_stack **stack_b);
void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_ins_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_bench_update(t_stack *stack, t_op op);
int		ft_strcmp_flag(const char *s1, const char *s2);
int		ft_is_flag(char *arg);
int		ft_remove_flags(int argc, char *argv[]);
int		ft_parse_flags(int argc, char *argv[], int *strategy, t_bench *bench);
double	ft_compute_disorder(t_stack *a, int size);
void	ft_link_bench(t_stack *a, int size, t_bench *bench);
void	ft_main_sort(t_app *app);
int		ft_checker_strcmp(const char *s1, const char *s2);
int		ft_checker_init(int argc, char *argv[], t_stack **stack_a);
void	ft_write_str(const char *s);
void	ft_write_int(int n);
void	ft_write_percent(double d);
void	ft_print_bench(t_bench *b);

#endif
