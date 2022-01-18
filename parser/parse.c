/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:50:46 by hakim             #+#    #+#             */
/*   Updated: 2022/01/13 13:50:47 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*split_arg(char *input, t_deque *a)
{
	int		count;
	int		*temp;
	char	**splitted;

	splitted = ft_split(input, ' ');
	if (splitted == 0)
		return (0);
	count = 0;
	while (splitted[count] != 0)
		++count;
	temp = malloc(sizeof(int) * count);
	if (temp == 0)
		return (ft_free_split(splitted));
	count = -1;
	while (splitted[++count] != 0)
	{
		if (put_n_check(splitted, temp, count) == FALSE)
			return (ft_free_split(splitted));
	}
	a->capacity = count;
	ft_free_split(splitted);
	return (carve(temp, count));
}

int	*put_args(int ac, char **av, t_deque *a)
{
	int		count;
	int		last;
	int		*temp;

	last = ac - 1;
	temp = malloc(sizeof(int) * last);
	if (temp == 0)
		return (0);
	count = -1;
	while (++count < last)
		if (put_n_check(av, temp, count) == FALSE)
			return (0);
	a->capacity = count;
	return (carve(temp, count));
}

t_bool	put_n_check(char **words, int *toput, int count)
{
	if (ps_strtoll(words[count], &toput[count]) == FALSE)
	{
		ft_free_intarr(toput);
		return (FALSE);
	}
	if (check_typo(words[count]) == FALSE)
	{
		ft_free_intarr(toput);
		return (FALSE);
	}
	if (check_dup(toput, count) == FALSE)
	{
		ft_free_intarr(toput);
		return (FALSE);
	}
	return (TRUE);
}

int	*carve(int *temp, int count)
{
	int		*carved;
	int		index;
	int		tmpdex;

	carved = malloc(sizeof(int) * count);
	if (carved == 0)
	{
		ft_free_intarr(temp);
		return (0);
	}
	index = -1;
	while (++index < count)
		carved[index] = temp[index];
	temp = merge_sort(temp, count);
	index = -1;
	while (++index < count)
	{
		tmpdex = 0;
		while (temp[tmpdex] != carved[index])
			++tmpdex;
		carved[index] = tmpdex;
	}
	ft_free_intarr(temp);
	return (carved);
}

int	*prep_stack(int *carved, t_deque *a, t_deque *b)
{
	int	index;

	deque_init(a, 'a');
	if (a->stack == 0)
	{
		ft_free_intarr(carved);
		return (0);
	}
	b->capacity = a->capacity;
	deque_init(b, 'b');
	if (b->stack == 0)
	{
		ft_free_intarr(a->stack);
		ft_free_intarr(carved);
		return (0);
	}
	index = -1;
	while (++index < a->capacity)
		push_bottom(a, carved[index]);
	return (carved);
}
