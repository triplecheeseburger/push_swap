/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:47:38 by hakim             #+#    #+#             */
/*   Updated: 2022/01/14 00:47:40 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	deque_init(t_deque *deque, char name)
{
	deque->name = name;
	deque->stack = malloc(sizeof(int) * (deque->capacity + 1));
	if (deque->stack == 0)
		return (FALSE);
	deque->top = 0;
	deque->bottom = 0;
	return (TRUE);
}

void	push_top(t_deque *deque, int topush)
{
	deque->top = adjust_index(deque, deque->top - 1);
	deque->stack[deque->top] = topush;
}

void	push_bottom(t_deque *deque, int topush)
{
	deque->stack[deque->bottom] = topush;
	deque->bottom = adjust_index(deque, deque->bottom + 1);
}

int	pop_top(t_deque *deque)
{
	int	temp;

	temp = deque->top;
	deque->top = adjust_index(deque, deque->top + 1);
	return (deque->stack[temp]);
}

int	pop_bottom(t_deque *deque)
{
	deque->bottom = adjust_index(deque, deque->bottom - 1);
	return (deque->stack[deque->bottom]);
}
