#include "push_swap.h"

static int	ft_strcmp_flag(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	ft_is_flag(char *arg)
{
	if (!arg)
		return (0);
	if (ft_strcmp_flag(arg, "--bench") == 0)
		return (1);
	if (ft_strcmp_flag(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp_flag(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp_flag(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp_flag(arg, "--adaptive") == 0)
		return (1);
	return (0);
}

static int	ft_remove_flags(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (ft_is_flag(argv[i]))
		{
			j = i;
			while (j < argc - 1)
			{
				argv[j] = argv[j + 1];
				j++;
			}
			argc--;
			i--;
		}
		i++;
	}
	return (argc);
}

static int	ft_parse_flags(int argc, char *argv[],
				int *strategy, t_bench *bench)
{
	int	i;

	i = 1;
	*strategy = FLAG_ADAPTIVE;
	while (i < argc)
	{
		if (ft_strcmp_flag(argv[i], "--bench") == 0)
			bench->enabled = 1;
		else if (ft_strcmp_flag(argv[i], "--simple") == 0)
			*strategy = FLAG_SIMPLE;
		else if (ft_strcmp_flag(argv[i], "--medium") == 0)
			*strategy = FLAG_MEDIUM;
		else if (ft_strcmp_flag(argv[i], "--complex") == 0)
			*strategy = FLAG_COMPLEX;
		else if (ft_strcmp_flag(argv[i], "--adaptive") == 0)
			*strategy = FLAG_ADAPTIVE;
		i++;
	}
	return (0);
}

static double	ft_compute_disorder(t_stack *a, int size)
{
	int		*arr;
	int		i;
	int		j;
	long	mistakes;
	long	total;
	t_stack	*cur;

	if (size <= 1)
		return (0.0);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0.0);
	cur = a;
	i = 0;
	while (i < size)
	{
		arr[i++] = cur->index;
		cur = cur->next;
	}
	mistakes = 0;
	total = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	free(arr);
	return ((double)mistakes / (double)total);
}

/*
** Collega il puntatore bench a ogni nodo dello stack
** senza questo ft_bench_update trova bench NULL e non conta nulla
*/
static void	ft_link_bench(t_stack *a, int size, t_bench *bench)
{
	t_stack	*cur;
	int		i;

	cur = a;
	i = 0;
	while (i < size)
	{
		cur->bench = bench;
		cur = cur->next;
		i++;
	}
}

static void	ft_main_sort(int argc, int strategy,
				double disorder,
				t_stack **a, t_stack **b)
{
	if (argc - 1 <= 4)
		ft_sort_few(a, b, argc - 1);
	else
	{
		if (strategy == FLAG_SIMPLE)
			ft_ins_sort(a, b);
		else if (strategy == FLAG_MEDIUM)
			ft_chunk_sort(a, b);
		else if (strategy == FLAG_COMPLEX)
			ft_sort_everything(a, b);
		else
		{
			if (disorder < 0.2)
				ft_ins_sort(a, b);
			else if (disorder < 0.5)
				ft_chunk_sort(a, b);
			else
				ft_sort_everything(a, b);
		}
	}
}

/*
** Stampa il bench su stderr con write() puro, senza dipendere da ft_dprintf
** per i float. Usiamo una helper che scrive un intero e una per la percentuale.
*/
static void	write_str(const char *s)
{
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
}

static void	write_int(int n)
{
	char	buf[12];
	int		i;
	int		neg;

	i = 11;
	buf[i] = '\0';
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	if (n == 0)
		buf[--i] = '0';
	while (n > 0)
	{
		buf[--i] = '0' + (n % 10);
		n /= 10;
	}
	if (neg)
		buf[--i] = '-';
	write(2, buf + i, 11 - i);
}

static void	write_percent(double d)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)(d * 100.0);
	decimal_part = (int)(d * 10000.0) % 100;
	if (decimal_part < 0)
		decimal_part = -decimal_part;
	write_int(integer_part);
	write(2, ".", 1);
	if (decimal_part < 10)
		write(2, "0", 1);
	write_int(decimal_part);
}

static void	ft_print_bench(t_bench *b)
{
	if (!b || !b->enabled)
		return ;
	write_str("\n========== BENCH ==========\n");
	write_str("disorder: ");
	write_percent(b->disorder);
	write_str("%\n");
	write_str("strategy: ");
	write_int(b->strategy);
	write_str("\n");
	write_str("ops total: ");
	write_int(b->total_ops);
	write_str("\n");
	write_str("sa:"); write_int(b->sa);
	write_str(" sb:"); write_int(b->sb);
	write_str(" ss:"); write_int(b->ss);
	write_str("\n");
	write_str("pa:"); write_int(b->pa);
	write_str(" pb:"); write_int(b->pb);
	write_str("\n");
	write_str("ra:"); write_int(b->ra);
	write_str(" rb:"); write_int(b->rb);
	write_str(" rr:"); write_int(b->rr);
	write_str("\n");
	write_str("rra:"); write_int(b->rra);
	write_str(" rrb:"); write_int(b->rrb);
	write_str(" rrr:"); write_int(b->rrr);
	write_str("\n");
	write_str("===========================\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		strategy;
	t_bench	bench;
	int		*arr;
	double	disorder;

	if (argc <= 1)
		return (0);
	ft_memset(&bench, 0, sizeof(t_bench));
	a = NULL;
	b = NULL;
	if (ft_parse_flags(argc, argv, &strategy, &bench) == -1)
		return (write(2, "Error\n", 6), 1);
	argc = ft_remove_flags(argc, argv);
	if (argc <= 1)
		return (0);
	if (!ft_check_errors(argc, argv))
		return (write(2, "Error\n", 6), 1);
	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (0);
	if (!ft_array_handling(argc, argv, arr, &a))
		return (free(arr), 0);
	free(arr);
	disorder = ft_compute_disorder(a, argc - 1);
	bench.disorder = disorder;
	bench.strategy = strategy;
	ft_link_bench(a, argc - 1, &bench);  // <- fix: collega bench a ogni nodo
	if (!ft_check_order(a, argc - 1))
		ft_main_sort(argc, strategy, disorder, &a, &b);
	ft_print_bench(&bench);              // <- fix: stampa corretta senza ft_dprintf
	ft_free_stack(&a, ft_lst_count(a));
	if (b)
		ft_free_stack(&b, ft_lst_count(b));
	return (0);
}