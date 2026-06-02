/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurossi <lurossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/06/02 11:29:46 by lurossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp_flag(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_is_flag(char *arg)
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

int	ft_remove_flags(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_is_flag(argv[i]))
		{
			ft_shift_args(argv, i, argc);
			argc--;
			i--;
		}
		i++;
	}
	return (argc);
}
