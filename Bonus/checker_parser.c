/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:17:06 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/27 18:45:21 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_dup(int *a)
{
	int	i;
	int	j;

	i = a[0];
	while (a && i > 0)
	{
		j = i - 1;
		while (j > 0)
		{
			if (a[j] == a[i])
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int	atoi_app(char **s, int *a, int i)
{
	if (!s[0])
	{
		write(2, "Error\n", 6);
		fr_s(s);
		exit(1);
	}
	i--;
	while (i >= 0)
	{
		a[0]++;
		if (ft_strlen(s[i]) == 0 || ft_strlen(s[i]) > 11
			|| ((ft_strlen(s[i]) == 11 || ft_strlen(s[i]) == 10)
				&& (ft_atoi(s[i]) > 2147483647 || ft_atoi(s[i]) < -2147483648)))
		{
			write(2, "Error\n", 6);
			fr_s(s);
			exit(1);
		}
		a[a[0]] = ft_atoi(s[i]);
		i--;
	}
	fr_s(s);
	return (1);
}

int	ft_check(char *a, int *stack)
{
	int		i;
	char	**str;
	int		j;

	i = 0;
	str = ft_split(a, ' ');
	while (str && str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((!ft_isdigit(str[i][j]) && str[i][j] != '-' && str[i][j] != '+')
				|| ((str[i][j] == '-' || str[i][j] == '+') && ft_strlen(a) < 2))
			{
				fr_s(str);
				free(stack);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	atoi_app(str, stack, i);
	return (1);
}

int	*ft_pars(char **a, int c)
{
	int	i;
	int	*r;
	int	k;

	i = 1;
	k = 0;
	while (i < c)
	{
		k += wc(a[i], ' ');
		i++;
	}
	r = ft_calloc(sizeof(int), (k + 1));
	if (!r)
		return (0);
	c--;
	while (c > 0)
	{
		ft_check(a[c], r);
		c--;
	}
	return (r);
}
