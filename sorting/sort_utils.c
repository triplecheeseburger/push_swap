/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 02:13:05 by hakim             #+#    #+#             */
/*   Updated: 2022/01/14 02:13:06 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_my_place_in(t_deque *deque, int me)
{
	int	index;
	int	next;

	index = adjust_index(deque, deque->top);
	while (index != deque->bottom)
	{
		if (deque->stack[index] == is_next(deque, me))
			break ;
		index = adjust_index(deque, index + 1);
	}
	next = deque->stack[index];
	if (index == deque->top)
		return ;
	rotate_toward_nearest(deque, next, index);
}

void	rotate_until_sorted(t_deque *deque)
{
	int	mindex;
	int	min;

	mindex = deque->top;
	min = get_min(deque);
	while (mindex != deque->bottom)
	{
		if (deque->stack[mindex] == min)
			break ;
		mindex = adjust_index(deque, mindex + 1);
	}
	rotate_toward_nearest(deque, min, mindex);
}

void	rotate_toward_nearest(t_deque *deque, int target, int tardex)
{
	if (get_deque_len(deque, deque->top, tardex)
		< get_deque_len(deque, tardex, deque->bottom))
		while (target != deque->stack[deque->top])
			rotate(deque);
	else
		while (target != deque->stack[deque->top])
			reverse_rotate(deque);
}
