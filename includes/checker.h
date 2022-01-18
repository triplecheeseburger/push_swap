/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 04:17:10 by hakim             #+#    #+#             */
/*   Updated: 2022/01/19 04:17:11 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line.h"

void	read_n_operate(t_deque *a, t_deque *b);
t_bool	operate(char *line, t_deque *a, t_deque *b);
int		checker_error(int mode);

void	checker_swap(t_deque *deque);
void	checker_ss(t_deque *a, t_deque *b);
void	checker_push_from_to(t_deque *from, t_deque *to);
void	checker_rotate(t_deque *deque);
void	checker_rr(t_deque *a, t_deque *b);
void	checker_reverse_rotate(t_deque *deque);
void	checker_rrr(t_deque *a, t_deque *b);

#endif
