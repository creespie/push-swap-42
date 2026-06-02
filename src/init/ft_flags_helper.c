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

void	ft_flag_checker(char *flag, int *strategy, int *numbers_flags)
{
	(*numbers_flags)++;
	if (ft_strcmp_flag(flag, "--simple") == 0)
		*strategy = FLAG_SIMPLE;
	else if (ft_strcmp_flag(flag, "--medium") == 0)
		*strategy = FLAG_MEDIUM;
	else if (ft_strcmp_flag(flag, "--complex") == 0)
		*strategy = FLAG_COMPLEX;
	else if (ft_strcmp_flag(flag, "--adaptive") == 0)
		*strategy = FLAG_ADAPTIVE;
}
