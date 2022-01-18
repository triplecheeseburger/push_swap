/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:41:27 by hakim             #+#    #+#             */
/*   Updated: 2022/01/14 01:41:28 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_deque *a, t_deque *b)
{
	if (is_deque_sorted(a) == TRUE)
		return ;
	if (a->capacity == 1)
		return ;
	else if (a->capacity == 2)
		sort_two(a);
	else if (a->capacity == 3)
		sort_three(a);
	else if (a->capacity <= 5)
		sort_five(a, b);
	else
		sort_big(a, b);
}
