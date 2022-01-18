/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:49:25 by hakim             #+#    #+#             */
/*   Updated: 2022/01/14 00:49:27 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_deque *deque)
{
	push_bottom(deque, pop_top(deque));
	write(1, "r", 1);
	write(1, &deque->name, 1);
	write(1, "\n", 1);
}

void	rr(t_deque *a, t_deque *b)
{
	push_bottom(a, pop_top(a));
	push_bottom(b, pop_top(b));
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_deque *deque)
{
	push_top(deque, pop_bottom(deque));
	write(1, "rr", 2);
	write(1, &deque->name, 1);
	write(1, "\n", 1);
}

void	rrr(t_deque *a, t_deque *b)
{
	push_top(a, pop_bottom(a));
	push_top(b, pop_bottom(b));
	write(1, "rrr\n", 4);
}
