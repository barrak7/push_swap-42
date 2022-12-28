/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:55:08 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/22 19:21:42 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *a)
{
	int	tmp;

	tmp = a[a[0]];
	a[a[0]] = a[a[0] - 1];
	a[a[0] - 1] = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(int *b)
{
	int	tmp;

	tmp = b[b[0]];
	b[b[0]] = b[b[0] - 1];
	b[b[0] - 1] = tmp;
	write(1, "sb\n", 3);
}

int	indway(int *b, int i, int v)
{
	if (i >= b[0] / 2)
	{
		while (i <= b[0])
		{
			if (b[i] == v)
				return (1);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			if (b[i] == v)
				return (1);
			i--;
		}
	}
	if (b[b[0]] == v)
		return (1);
	return (0);
}

int	push_max2(int *a, int *b, int *arr, int i)
{
	int	p;

	p = 0;
	if (s_closer(get_index(b, arr[i - 2]), get_index(b, arr[i - 1]), b)
		|| indway(b, get_index(b, arr[i - 1]), arr[i - 2]))
	{
		rotate_index(b, get_index(b, arr[i - 2]), 'b');
		p = 1;
	}
	if (p)
	{
		push_a(b, a);
		rotate(a, 'a');
		tko_i(arr, i - 2, &i);
	}
	rotate_index(b, get_index(b, arr[i - 1]), 'b');
	push_a(b, a);
	tko_i(arr, i - 1, &i);
	if (p)
		return (2);
	return (1);
}

void	tko_i(int *arr, int i, int *end)
{
	while (i < arr[0])
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[0] -= 1;
	(*end)--;
}
