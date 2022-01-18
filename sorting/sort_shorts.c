/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_shorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:36:58 by hakim             #+#    #+#             */
/*   Updated: 2022/01/14 01:37:01 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_deque *deque)
{
	swap(deque);
}

void	sort_three(t_deque *deque)
{
	int	first;
	int	second;
	int	third;

	first = peep_top(deque);
	second = deque->stack[get_index(deque, deque->top + 1)];
	third = peep_bottom(deque);
	if (first < second && second > third && third > first)
	{
		swap(deque);
		rotate(deque);
	}
	if (first < second && second > third && third < first)
		reverse_rotate(deque);
	if (first > second && second < third && third > first)
		swap(deque);
	if (first > second && second < third && third < first)
		rotate(deque);
	if (first > second && second > third && third < first)
	{
		swap(deque);
		reverse_rotate(deque);
	}
}

void	sort_five(t_deque *a, t_deque *b)
{
	if (get_deque_len(a, a->top, a->bottom) == 5)
		push_from_to(a, b);
	push_from_to(a, b);
	if (is_deque_sorted(a) == FALSE)
		sort_three(a);
	while (get_deque_len(b, b->top, b->bottom) != 0)
	{
		find_my_place_in(a, peep_top(b));
		push_from_to(b, a);
	}
	rotate_until_sorted(a);
}
