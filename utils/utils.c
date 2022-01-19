/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:04:57 by hakim             #+#    #+#             */
/*   Updated: 2022/01/09 19:05:00 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_occurred(int mode)
{
	write(2, "Error\n", 6);
	if (mode == MALLOC_ERROR)
		exit(0);
	return (0);
}

int	*ft_free_intarr(int *arr)
{
	free(arr);
	arr = 0;
	return (0);
}

void	ft_intset(int *arr, int n, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		arr[index] = n;
		++index;
	}
}

t_bool	stack_empty(t_deque *deque)
{
	if (deque->top == deque->bottom)
		return (TRUE);
	return (FALSE);
}

t_bool	is_deque_sorted(t_deque *deque)
{
	int	index;
	int	former;

	if (get_deque_len(deque, deque->top, deque->bottom) == 1)
		return (TRUE);
	index = deque->top;
	while (adjust_index(deque, index + 1) != deque->bottom)
	{
		former = deque->stack[index];
		index = adjust_index(deque, index + 1);
		if (former >= deque->stack[index])
			return (FALSE);
	}
	return (TRUE);
}
