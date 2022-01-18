/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:23:50 by hakim             #+#    #+#             */
/*   Updated: 2022/01/18 12:23:57 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_lis(t_deque *deque)
{
	int	*temp;
	int	*lis;

	temp = malloc(sizeof(int) * deque->capacity + 1);
	if (temp == 0)
		return (0);
	lis = malloc(sizeof(int) * deque->capacity + 1);
	if (lis == 0)
		return (0);
	ft_intset(temp, -1, deque->capacity + 1);
	ft_intset(lis, -1, deque->capacity + 1);
	temp = get_lis_seq(deque, temp, lis);
	ft_intset(lis, -1, deque->capacity + 1);
	lis = back_trace(deque, lis, temp);
	ft_free_intarr(temp);
	return (lis);
}

int	*back_trace(t_deque *deque, int *lis, int *temp)
{
	int	count;
	int	tdex;
	int	mindex;

	count = 0;
	tdex = 0;
	mindex = get_mindex(deque);
	while (temp[tdex] != -1)
	{
		if (temp[tdex] > count)
			count = temp[tdex];
		tdex++;
	}
	while (count > 0)
	{
		if (temp[tdex] == count)
		{
			lis[count - 1] = deque->stack[get_index(deque, mindex + tdex)];
			--count;
		}
		--tdex;
	}
	return (lis);
}

int	*get_lis_seq(t_deque *deque, int *temp, int *stack)
{
	int	tmpdex;
	int	deqdex;
	int	cur;

	tmpdex = 1;
	temp[0] = 1;
	stack[0] = get_min(deque);
	deqdex = get_mindex(deque);
	while (tmpdex < deque->capacity)
	{
		cur = deque->stack[get_index(deque, deqdex + tmpdex)];
		temp[tmpdex] = put_stack(cur, stack);
		++tmpdex;
	}
	return (temp);
}

int	put_stack(int cur, int *stack)
{
	int	stkdex;

	stkdex = 0;
	while (stack[stkdex] != -1)
	{
		if (stack[stkdex] > cur)
		{
			stack[stkdex] = cur;
			return (stkdex + 1);
		}
		++stkdex;
	}
	stack[stkdex] = cur;
	return (stkdex + 1);
}
