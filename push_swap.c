/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:22:47 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/26 17:20:49 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ps_sort(int *b, int *a, int *arr)
{
	int	i;
	int	p;

	i = arr[0];
	while (i > 0)
	{
		p = 0;
		if (s_closer(get_index(b, arr[i - 1]), get_index(b, arr[i]), b)
			|| indway(b, get_index(b, arr[i]), arr[i - 1]))
		{
			p = push_max2(a, b, arr, i);
			if (p == 1)
				i--;
			if (p == 2)
				i -= 2;
		}
		rotate_index(b, get_index(b, arr[i]), 'b');
		push_a(b, a);
		if (p)
			swap_a(a);
		if (p == 2)
			rev_rotate(a, 'a');
		i--;
	}
	free(arr);
}

static void	ps_app(int *a, int *b, int *arr)
{
	int	start;
	int	end;
	int	offset;
	int	mid;
	int	i;

	offset = get_offset(a[0]);
	start = 1;
	end = offset;
	mid = arr[end / 2];
	while (arr[0])
	{
		i = get_nearest_of(a, arr, start, &end);
		rotate_index(a, i, 'a');
		push_b(a, b);
		if (b[b[0]] < mid)
			rotate(b, 'b');
		if (end < start)
		{
			mid = arr[offset / 2];
			end = offset;
		}
		if (end >= arr[0])
			end = arr[0];
	}
}

static void	push_swap(int *a)
{
	int	*f;
	int	*b;
	int	*tmp;

	b = malloc(sizeof(int) * (a[0] + 1));
	if (!b)
		return ;
	b[0] = 0;
	f = ft_dup_arr(a);
	if (!f)
		return ;
	ft_sort(f);
	if (a[0] <= 50)
	{
		sm_sort(a, b, f);
		return ;
	}
	tmp = ft_dup_arr(f);
	if (!tmp)
		return ;
	ps_app(a, b, tmp);
	free(tmp);
	ps_sort(b, a, f);
	free(b);
}

int	main(int argc, char **argv)
{
	int	*a;

	a = ft_pars(argv, argc);
	is_dup(a);
	if (!a || is_sorted(a))
		return (0);
	push_swap(a);
	return (0);
}
