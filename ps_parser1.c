/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:05:57 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/26 17:22:36 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *a)
{
	int	i;
	int	j;

	i = a[0];
	while (a && i > 0)
	{
		j = i - 1;
		while (j > 0)
		{
			if (a[j] < a[i])
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

void	is_dup(int *a)
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
}
