/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:53:30 by hakim             #+#    #+#             */
/*   Updated: 2022/01/19 01:53:31 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pos(int ago, int bgo, t_deque *a, t_deque *b)
{
	int	both;
	int	temp;

	both = calc_both(ago, bgo);
	temp = both;
	if (ago > 0)
	{
		while (temp-- > 0)
			rr(a, b);
	}
	else
	{
		while (temp-- > 0)
			rrr(a, b);
	}
	r_or_rr(a, ago, both);
	r_or_rr(b, bgo, both);
}

int	calc_both(int a, int b)
{
	int	both;

	both = 0;
	if (a > 0 && b > 0)
		both = ft_min(a, b);
	else if (a < 0 && b < 0)
		both = -ft_max(a, b);
	return (both);
}

int	calc_togo(int a, int b)
{
	int	both;

	both = calc_both(a, b);
	return (ft_max(a, b) - ft_min(a, b) + both);
}

void	r_or_rr(t_deque *deque, int go, int both)
{
	int	index;

	index = 0;
	while (index < ft_abs(go) - both)
	{
		if (go > 0)
			rotate(deque);
		else
			reverse_rotate(deque);
		++index;
	}
}

void	get_best_pos(int *pos, t_deque *a, t_deque *b, int index)
{
	int	totop;
	int	tobot;
	int	next;

	totop = get_deque_len(b, b->top, index);
	tobot = get_deque_len(b, index, b->bottom);
	if (totop < tobot)
		pos[1] = totop;
	else
		pos[1] = -tobot;
	next = is_next(a, b->stack[index]);
	index = a->top;
	while (index != a->bottom)
	{
		if (a->stack[index] == next)
			break ;
		index = adjust_index(a, index + 1);
	}
	totop = get_deque_len(a, a->top, index);
	tobot = get_deque_len(a, index, a->bottom);
	if (totop < tobot)
		pos[0] = totop;
	else
		pos[0] = -tobot;
}
