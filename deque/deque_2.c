/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:12:45 by hakim             #+#    #+#             */
/*   Updated: 2022/01/14 00:47:54 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	adjust_index(t_deque *deque, int index)
{
	if (index < 0)
		index = (deque->capacity + 1) + index;
	if (index > deque->capacity)
		index = index - (deque->capacity + 1);
	return (index);
}

int	get_index(t_deque *deque, int index)
{
	if (index < 0)
		index = (deque->capacity + 1) + index;
	if (index >= deque->capacity)
		index = index - deque->capacity;
	return (index);
}

int	peep_top(t_deque *deque)
{
	deque->top = adjust_index(deque, deque->top);
	return (deque->stack[deque->top]);
}

int	peep_bottom(t_deque *deque)
{
	return (deque->stack[adjust_index(deque, deque->bottom - 1)]);
}
