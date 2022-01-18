/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_oper_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 04:19:36 by hakim             #+#    #+#             */
/*   Updated: 2022/01/19 04:19:37 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_swap(t_deque *deque)
{
	int	temp;
	int	tmpdex;

	temp = deque->stack[deque->top];
	tmpdex = adjust_index(deque, deque->top + 1);
	deque->stack[deque->top] = deque->stack[tmpdex];
	deque->stack[tmpdex] = temp;
}

void	checker_ss(t_deque *a, t_deque *b)
{
	checker_swap(a);
	checker_swap(b);
}

void	checker_push_from_to(t_deque *from, t_deque *to)
{
	push_top(to, pop_top(from));
}
