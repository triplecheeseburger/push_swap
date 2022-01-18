/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:28:30 by hakim             #+#    #+#             */
/*   Updated: 2022/01/19 02:28:33 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		return (checker_error(INPUT_ERROR));
	carved = prep_stack(carved, &a, &b);
	if (carved == 0)
		return (checker_error(MALLOC_ERROR));
	ft_free_intarr(carved);
	read_n_operate(&a, &b);
	if (is_deque_sorted(&a) == TRUE)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_intarr(a.stack);
	ft_free_intarr(b.stack);
	return (0);
}

void	read_n_operate(t_deque *a, t_deque *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (operate(line, a, b) == FALSE)
		{
			write(2, "Error\n", 6);
			ft_free_intarr(a->stack);
			ft_free_intarr(b->stack);
			exit(0);
		}
		free(line);
		line = 0;
		line = get_next_line(0);
	}
	free(line);
	line = 0;
}

t_bool	operate(char *line, t_deque *a, t_deque *b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		checker_swap(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		checker_swap(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		checker_ss(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		checker_push_from_to(b, a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		checker_push_from_to(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		checker_rotate(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		checker_rotate(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		checker_rr(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		checker_reverse_rotate(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		checker_reverse_rotate(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		checker_rrr(a, b);
	else
		return (FALSE);
	return (TRUE);
}

int	checker_error(int mode)
{
	write(2, "Error\n", 6);
	if (mode == MALLOC_ERROR)
		exit(0);
	return (0);
}
