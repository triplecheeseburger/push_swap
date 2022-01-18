/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_gets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 01:52:06 by hakim             #+#    #+#             */
/*   Updated: 2022/01/15 01:52:08 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_deque_len(t_deque *deque, int top, int bottom)
{
	if (top <= bottom)
		return (bottom - top);
	else
		return (deque->capacity - top + bottom + 1);
}

int	get_min(t_deque *deque)
{
	int	min;
	int	index;

	min = deque->capacity;
	index = deque->top;
	while (index != deque->bottom)
	{
		if (deque->stack[index] < min)
			min = deque->stack[index];
		index = adjust_index(deque, index + 1);
	}
	return (min);
}

int	get_mindex(t_deque *deque)
{
	int	min;
	int	mindex;
	int	index;

	min = deque->capacity;
	index = deque->top;
	while (index != deque->bottom)
	{
		if (deque->stack[index] < min)
		{
			mindex = index;
			min = deque->stack[index];
		}
		index = adjust_index(deque, index + 1);
	}
	return (mindex);
}

int	get_max(t_deque *deque)
{
	int	max;
	int	index;

	max = 0;
	index = deque->top;
	while (index != deque->bottom)
	{
		if (deque->stack[index] > max)
			max = deque->stack[index];
		index = adjust_index(deque, index + 1);
	}
	return (max);
}

int	is_next(t_deque *deque, int me)
{
	int	last_diff;
	int	index;
	int	remem;

	if (me > get_max(deque))
		return (get_min(deque));
	index = deque->top;
	last_diff = get_max(deque) - me;
	remem = get_max(deque);
	while (index != deque->bottom)
	{
		if (last_diff > deque->stack[index] - me && deque->stack[index] > me)
		{
			last_diff = deque->stack[index] - me;
			remem = deque->stack[index];
		}
		index = adjust_index(deque, index + 1);
	}
	return (remem);
}
