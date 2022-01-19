/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:26:28 by hakim             #+#    #+#             */
/*   Updated: 2022/01/13 17:26:30 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define ARR 0
#define SORTED 1

void	merge(int **arr, int start, int mid, int end)
{
	int	foredex;
	int	reardex;
	int	sortdex;

	foredex = start;
	reardex = mid + 1;
	sortdex = start;
	while (foredex <= mid && reardex <= end)
	{
		if (arr[ARR][foredex] <= arr[ARR][reardex])
			arr[SORTED][sortdex++] = arr[ARR][foredex++];
		else
			arr[SORTED][sortdex++] = arr[ARR][reardex++];
	}
	if (foredex <= mid)
		while (foredex <= mid)
			arr[SORTED][sortdex++] = arr[ARR][foredex++];
	else
		while (reardex <= end)
			arr[SORTED][sortdex++] = arr[ARR][reardex++];
	sortdex = start - 1;
	while (++sortdex <= end)
		arr[ARR][sortdex] = arr[SORTED][sortdex];
}

void	merge_recursive(int **arr, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_recursive(arr, start, mid);
		merge_recursive(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int	*merge_sort(int *temp, int count)
{
	int	**arr;
	int	*sorted;

	arr = malloc(sizeof(int *) * 2);
	if (arr == 0)
		return (ft_free_intarr(temp));
	sorted = malloc(sizeof(int) * count);
	if (sorted == 0)
	{
		free(arr);
		arr = 0;
		return (ft_free_intarr(temp));
	}
	arr[0] = temp;
	arr[1] = sorted;
	merge_recursive(arr, 0, count - 1);
	ft_free_intarr(sorted);
	free(arr);
	arr = 0;
	return (temp);
}
