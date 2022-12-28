/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:22:42 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/22 19:27:57 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nearest_btm(int *a, int *target, int start, int end)
{
	int	i;
	int	j;

	i = 1;
	while (i <= a[0])
	{
		j = start;
		while (j <= end)
		{
			if (a[i] == target[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	get_nearest_top(int *a, int *target, int start, int end)
{
	int	i;
	int	j;

	i = a[0];
	while (i > 0)
	{
		j = start;
		while (j <= end)
		{
			if (a[i] == target[j])
				return (i);
			j++;
		}
		i--;
	}
	return (i);
}

int	get_nearest_of(int *a, int *target, int start, int *end)
{
	int	i;
	int	j;

	i = get_nearest_btm(a, target, start, *end);
	j = get_nearest_top(a, target, start, *end);
	if ((j >= a[0] / 2 && a[0] - j < i) || j < i)
	{
		tko_i(target, get_index(target, a[j]), end);
		return (j);
	}
	tko_i(target, get_index(target, a[i]), end);
	return (i);
}

int	s_closer(int s, int j, int *b)
{
	if (s == 0)
		return (0);
	if (j >= b[0] / 2 && s < b[0] / 2 && s < b[0] - j)
		return (1);
	else if (j < b[0] / 2 && s >= b[0] / 2 && b[0] - s < j)
		return (1);
	return (0);
}
