/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/06/02 14:16:03 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	ft_prepare_stack(int argc, char *argv[], t_app *app)
{
	char	**nums;
	int		num_argc;
	int		*arr;

	nums = ft_split_args(argc, argv, &num_argc);
	if (!nums)
		return (write(2, "Error\n", 6), 0);
	if (num_argc <= 1)
		return (ft_free_split_args(nums), 0);
	if (!ft_check_errors(num_argc, nums))
		return (ft_free_split_args(nums), 0);
	arr = malloc(sizeof(int) * (num_argc - 1));
	if (!arr)
		return (ft_free_split_args(nums), 0);
	if (!ft_array_handling(num_argc, nums, arr, &app->a))
		return (free(arr), ft_free_split_args(nums), 0);
	app->argc = num_argc;
	free(arr);
	ft_free_split_args(nums);
	return (1);
}

static int	ft_init_app(int argc, char *argv[], t_app *app)
{
	ft_memset(app, 0, sizeof(t_app));
	if (ft_parse_flags(argc, argv, &app->strategy, &app->bench) == -1)
		return (write(2, "Error\n", 6), 0);
	app->argc = ft_remove_flags(argc, argv);
	if (app->argc <= 1)
		return (0);
	if (!ft_prepare_stack(app->argc, argv, app))
		return (0);
	app->disorder = ft_compute_disorder(app->a, app->argc - 1);
	app->bench.disorder = app->disorder;
	app->bench.strategy = app->strategy;
	ft_link_bench(app->a, app->argc - 1, &app->bench);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_app	app;

	if (argc <= 1)
		return (0);
	if (!ft_init_app(argc, argv, &app))
		return (0);
	if (!ft_check_order(app.a, app.argc - 1))
		ft_main_sort(&app);
	ft_print_bench(&app.bench);
	ft_free_stack(&app.a, ft_lst_count(app.a));
	if (app.b)
		ft_free_stack(&app.b, ft_lst_count(app.b));
	return (0);
}
