/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_oper_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 04:19:45 by hakim             #+#    #+#             */
/*   Updated: 2022/01/19 04:19:46 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_rotate(t_deque *deque)
{
	push_bottom(deque, pop_top(deque));
}

void	checker_rr(t_deque *a, t_deque *b)
{
	push_bottom(a, pop_top(a));
	push_bottom(b, pop_top(b));
}

void	checker_reverse_rotate(t_deque *deque)
{
	push_top(deque, pop_bottom(deque));
}

void	checker_rrr(t_deque *a, t_deque *b)
{
	push_top(a, pop_bottom(a));
	push_top(b, pop_bottom(b));
}
