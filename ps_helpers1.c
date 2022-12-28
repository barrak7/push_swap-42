/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helpers1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:48:09 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/25 11:48:30 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int *a, int e)
{
	int	i;

	i = 1;
	while (i <= a[0])
	{
		if (a[i] == e)
			return (i);
		i++;
	}
	return (0);
}

void	rotate_index(int *a, int i, char c)
{
	if (i >= a[0] / 2)
	{
		i = a[0] - i;
		while (i > 0)
		{
			rotate(a, c);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			rev_rotate(a, c);
			i--;
		}
	}
}

int	get_offset(int i)
{
	if (i <= 150)
		return (i / 5);
	return (i / 9);
}
