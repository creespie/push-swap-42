#include "push_swap.h"

static int	ft_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static void	ft_free_tmp(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_free_split_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 1;
	while (args[i])
		free(args[i++]);
	free(args);
}

char	**ft_split_args(int argc, char **argv, int *new_argc)
{
	char	**tmp;
	char	**out;
	int		i;
	int		j;
	int		k;
	int		total;

	i = 1;
	total = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp || !tmp[0])
			return (ft_free_tmp(tmp), NULL);
		total += ft_tab_size(tmp);
		ft_free_tmp(tmp);
		i++;
	}
	out = malloc(sizeof(char *) * (total + 1));
	if (!out)
		return (NULL);
	out[0] = argv[0];
	i = 1;
	k = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (ft_free_split_args(out), NULL);
		j = 0;
		while (tmp[j])
			out[k++] = tmp[j++];
		free(tmp);
		i++;
	}
	out[k] = NULL;
	*new_argc = k;
	return (out);
}