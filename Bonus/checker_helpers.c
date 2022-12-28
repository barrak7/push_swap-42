/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:05:18 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/24 12:20:52 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_n_wr(int *a, int *b, char *str, int size)
{
	free(a);
	free(b);
	write(1, str, size);
}

void	wr_err(int *a, int *b, char *buffer)
{
	write(2, "Error\n", 6);
	free(a);
	free(b);
	free(buffer);
	exit(0);
}
