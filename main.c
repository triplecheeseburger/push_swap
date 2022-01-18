/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:38:10 by hakim             #+#    #+#             */
/*   Updated: 2022/01/07 18:38:13 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_deque	a;
	t_deque	b;
	int		*carved;

	if (ac < 2)
		return (0);
	else if (ac == 2)
		carved = split_arg(av[1], &a);
	else
		carved = put_args(ac, av + 1, &a);
	if (carved == 0)
		return (error_occurred(INPUT_ERROR));
	carved = prep_stack(carved, &a, &b);
	if (carved == 0)
		return (error_occurred(MALLOC_ERROR));
	ft_free_intarr(carved);
	push_swap(&a, &b);
	ft_free_intarr(a.stack);
	ft_free_intarr(b.stack);
	return (0);
}
