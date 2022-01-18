/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:22:07 by hakim             #+#    #+#             */
/*   Updated: 2022/01/17 12:22:08 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_deque *a, t_deque *b)
{
	int	*lis;

	lis = find_lis(a);
	if (lis == 0)
		error_occurred(MALLOC_ERROR);
	push_lis_elem(lis, a, b);
	while (get_deque_len(b, b->top, b->bottom) != 0)
	{
		find_best_friend(a, b);
		push_from_to(b, a);
	}
	rotate_until_sorted(a);
	ft_free_intarr(lis);
}

void	push_lis_elem(int *lis, t_deque *a, t_deque *b)
{
	int	count;

	count = 0;
	while (lis[count] != -1)
		++count;
	count = a->capacity - count;
	while (count)
	{
		if (is_in_arr(a->stack[a->top], lis) == FALSE)
		{
			push_from_to(a, b);
			--count;
		}
		else
			rotate(a);
	}
}

void	find_best_friend(t_deque *a, t_deque *b)
{
	int	index;
	int	pos[2];
	int	best;
	int	bestpos[2];

	index = b->top;
	best = b->capacity;
	while (index != b->bottom)
	{
		get_best_pos(pos, a, b, index);
		if (ft_abs(calc_togo(pos[0], pos[1])) < best)
		{
			best = ft_abs(calc_togo(pos[0], pos[1]));
			bestpos[0] = pos[0];
			bestpos[1] = pos[1];
		}
		index = adjust_index(b, index + 1);
	}
	do_pos(bestpos[0], bestpos[1], a, b);
}
