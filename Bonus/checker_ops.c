/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:57:39 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/24 11:46:55 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(int *a)
{
	int	tmp;
	int	i;

	if (a[0] < 2)
		return ;
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
}

void	rev_rotate(int *a)
{
	int	tmp;
	int	i;

	if (a[0] < 2)
		return ;
	tmp = a[1];
	i = 1;
	while (i + 1 <= a[0])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = tmp;
}

void	push_b(int *a, int *b)
{
	int	i;

	if (a[0] == 0)
		return ;
	i = b[0] + 1;
	b[i] = a[a[0]];
	a[0] -= 1;
	b[0] += 1;
}

void	push_a(int *b, int *a)
{
	int	i;

	if (b[0] == 0)
		return ;
	i = a[0] + 1;
	a[i] = b[b[0]];
	a[0] += 1;
	b[0] -= 1;
}

void	swap_a(int *a)
{
	int	tmp;

	if (a[0] < 2)
		return ;
	tmp = a[a[0]];
	a[a[0]] = a[a[0] - 1];
	a[a[0] - 1] = tmp;
}
