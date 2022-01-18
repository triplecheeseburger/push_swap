/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:06:31 by hakim             #+#    #+#             */
/*   Updated: 2022/01/09 19:06:32 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque *deque)
{
	int	temp;
	int	tmpdex;

	temp = deque->stack[deque->top];
	tmpdex = adjust_index(deque, deque->top + 1);
	deque->stack[deque->top] = deque->stack[tmpdex];
	deque->stack[tmpdex] = temp;
	write(1, "s", 1);
	write(1, &deque->name, 1);
	write(1, "\n", 1);
}

void	ss(t_deque *a, t_deque *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	push_from_to(t_deque *from, t_deque *to)
{
	push_top(to, pop_top(from));
	write(1, "p", 1);
	write(1, &to->name, 1);
	write(1, "\n", 1);
}
