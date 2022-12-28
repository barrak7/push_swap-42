/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:26:15 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/26 17:26:52 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int *a)
{
	if (is_sorted(a))
		return ;
	if (a[1] < a[2] && a[2] > a[3] && a[3] > a[1])
	{
		rev_rotate(a, 'a');
		return ;
	}
	else if (a[3] > a[2] && a[2] > a[1])
	{
		swap_a(a);
		rev_rotate(a, 'a');
		return ;
	}
	else if (a[3] > a[2] && a[2] < a[1] && a[3] > a[1])
	{
		rotate(a, 'a');
		return ;
	}
	else if (a[3] < a[2] && a[2] > a[1])
		rev_rotate(a, 'a');
	swap_a(a);
}

void	sm_push(int *b, int *a)
{
	while (b[0])
		push_a(b, a);
}

void	sm_sort(int *a, int *b, int *arr)
{
	int	i;

	i = 1;
	if (a[0] == 2)
		swap_a(a);
	while (i <= arr[0] && a[0] > 3)
	{
		rotate_index(a, get_index(a, arr[i]), 'a');
		push_b(a, b);
		i++;
	}
	if (a[0] == 3)
		sort_three(a);
	sm_push(b, a);
	free(arr);
	free(b);
}
