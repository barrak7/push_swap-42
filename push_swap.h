/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:36:04 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/28 19:13:40 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Bonus/gnl/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

void	push_a(int *b, int *a);
void	push_b(int *a, int *b);
void	rev_rotate(int *a, char c);
void	rotate(int *a, char c);
void	swap_b(int *b);
void	swap_a(int *a);
void	ft_sort(int *a);
void	ft_check(char *a, int *stack);
void	rotate_index(int *a, int i, char c);
void	tko_i(int *arr, int i, int *end);
void	is_dup(int *a);
void	sort_three(int *a);
void	sm_push(int *b, int *a);
void	sm_sort(int *a, int *b, int *arr);

int		*ft_dup_arr(int *a);
int		*ft_pars(char **a, int c);
int		is_sorted(int *a);
int		get_index(int *a, int e);
int		get_offset(int i);
int		get_nearest_of(int *a, int *target, int start, int *end);
int		indway(int *b, int i, int v);
int		push_max2(int *a, int *b, int *arr, int i);
int		get_nearest_btm(int *a, int *target, int start, int end);
int		get_nearest_top(int *a, int *target, int start, int end);
int		get_nearest_of(int *a, int *target, int start, int *end);
int		s_closer(int s, int j, int *b);

#endif
