/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:26:19 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/28 19:14:05 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int		*ft_pars(char **a, int c);
int		ft_check(char *a, int *stack);
int		is_dup(int *a);

void	rotate(int *a);
void	rev_rotate(int *a);
void	push_b(int *a, int *b);
void	push_a(int *b, int *a);
void	swap_a(int *a);
void	swap_b(int *b);
void	swap_x2(int *a, int *b);
void	rotate_x2(int *a, int *b);
void	rev_rotate_x2(int *a, int *b);
void	free_n_wr(int *a, int *b, char *str, int size);
void	wr_err(int *a, int *b, char *buffer);

#endif
