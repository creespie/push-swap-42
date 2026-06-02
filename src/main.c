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
