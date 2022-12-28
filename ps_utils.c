/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:53:40 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/22 19:23:57 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *a, char c)
{
	int	tmp;
	int	i;

	tmp = a[a[0]];
	i = a[0];
	if (i == 1)
		return ;
	while (i > 1)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = tmp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	rev_rotate(int *a, char c)
{
	int	tmp;
	int	i;

	tmp = a[1];
	i = 1;
	while (i + 1 <= a[0])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = tmp;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	push_b(int *a, int *b)
{
	int	i;

	i = b[0] + 1;
	b[i] = a[a[0]];
	a[0] -= 1;
	b[0] += 1;
	write(1, "pb\n", 3);
}

void	push_a(int *b, int *a)
{
	int	i;

	i = a[0] + 1;
	a[i] = b[b[0]];
	a[0] += 1;
	b[0] -= 1;
	write(1, "pa\n", 3);
}
