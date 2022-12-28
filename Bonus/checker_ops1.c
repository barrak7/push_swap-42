/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:45:08 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/24 12:04:58 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_b(int *b)
{
	int	tmp;

	if (b[0] < 2)
		return ;
	tmp = b[b[0]];
	b[b[0]] = b[b[0] - 1];
	b[b[0] - 1] = tmp;
}

void	swap_x2(int *a, int *b)
{
	swap_a(a);
	swap_b(b);
}

void	rotate_x2(int *a, int *b)
{
	rotate(a);
	rotate(b);
}

void	rev_rotate_x2(int *a, int *b)
{
	rev_rotate(a);
	rev_rotate(b);
}
