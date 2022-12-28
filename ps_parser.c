/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:58:46 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/26 17:23:34 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_dup_arr(int *a)
{
	int	i;
	int	*f;

	i = 1;
	f = malloc(sizeof(int) * (a[0] + 1));
	if (!f)
		return (0);
	f[0] = a[0];
	while (i <= a[0])
	{
		f[i] = a[i];
		i++;
	}
	return (f);
}

void	ft_sort(int *a)
{
	int	tmp;
	int	i;
	int	j;

	if (!a)
		return ;
	i = 1;
	while (i <= a[0])
	{
		j = i + 1;
		while (j <= a[0])
		{
			if (a[j] < a[i])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	atoi_app(char **s, int *a, int i)
{
	if (!s[0])
	{
		write(2, "Error\n", 6);
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
}

void	ft_check(char *a, int *stack)
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
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	atoi_app(str, stack, i);
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
	r = malloc(sizeof(int) * (k + 1));
	if (!r)
		return (0);
	r[0] = 0;
	c--;
	while (c > 0)
	{
		ft_check(a[c], r);
		c--;
	}
	return (r);
}
