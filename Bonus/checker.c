/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:25:58 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/26 16:50:37 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	is_sorted(int *a)
{
	int	i;
	int	j;

	i = a[0];
	while (i > 0)
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

int	in_app(char *buffer, int *a, int *b)
{
	if (!ft_strncmp(buffer, "sa\n", 3))
		swap_a(a);
	else if (!ft_strncmp(buffer, "sb\n", 3))
		swap_b(b);
	else if (!ft_strncmp(buffer, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(buffer, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(buffer, "ss\n", 3))
		swap_x2(a, b);
	else if (!ft_strncmp(buffer, "rr\n", 3))
		rotate_x2(a, b);
	else if (!ft_strncmp(buffer, "pa\n", 3))
		push_a(b, a);
	else if (!ft_strncmp(buffer, "pb\n", 3))
		push_b(a, b);
	else if (!ft_strncmp(buffer, "rra\n", 4))
		rev_rotate(a);
	else if (!ft_strncmp(buffer, "rrb\n", 4))
		rev_rotate(b);
	else if (!ft_strncmp(buffer, "rrr\n", 4))
		rev_rotate_x2(a, b);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	*buffer;

	a = ft_pars(argv, argc);
	if (argc == 1 || !a || is_dup(a))
	{
		free(a);
		return (0);
	}
	b = malloc(sizeof(int) * (a[0] + 1));
	b[0] = 0;
	buffer = get_next_line(0);
	while (buffer)
	{
		if (!in_app(buffer, a, b))
			wr_err(a, b, buffer);
		free(buffer);
		buffer = get_next_line(0);
	}
	if (is_sorted(a) && b[0] == 0)
		free_n_wr(a, b, "OK\n", 3);
	else
		free_n_wr(a, b, "KO\n", 3);
	return (0);
}
