/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:12:37 by hakim             #+#    #+#             */
/*   Updated: 2022/01/07 14:12:39 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define FALSE 0
# define TRUE 1
# define INPUT_ERROR 0
# define MALLOC_ERROR 1

typedef char	t_bool;
typedef struct s_deque
{
	char	name;
	int		*stack;
	int		top;
	int		bottom;
	int		capacity;
}	t_deque;

void	push_swap(t_deque *a, t_deque *b);

t_bool	deque_init(t_deque *deque, char name);
void	push_top(t_deque *deque, int topush);
void	push_bottom(t_deque *deque, int topush);
int		pop_top(t_deque *deque);
int		pop_bottom(t_deque *deque);
int		peep_top(t_deque *deque);
int		peep_bottom(t_deque *deque);
int		adjust_index(t_deque *deque, int index);
int		get_index(t_deque *deque, int index);

void	swap(t_deque *deque);
void	ss(t_deque *a, t_deque *b);
void	push_from_to(t_deque *from, t_deque *to);
void	rotate(t_deque *deque);
void	rr(t_deque *a, t_deque *b);
void	reverse_rotate(t_deque *deque);
void	rrr(t_deque *a, t_deque *b);

int		error_occurred(int mode);
int		is_in_arr(int a, int *lis);
int		ft_abs(int n);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		*ft_free_intarr(int *arr);
void	ft_intset(int *arr, int n, int size);
t_bool	stack_empty(t_deque *deque);
t_bool	is_deque_sorted(t_deque *deque);

int		*split_arg(char *input, t_deque *a);
int		*put_args(int ac, char **av, t_deque *a);
int		*carve(int *temp, int count);
int		*prep_stack(int *carved, t_deque *a, t_deque *b);
int		*ft_free_split(char **splitted);
t_bool	check_typo(const char *input);
t_bool	check_dup(const int *temp, int count);
t_bool	ps_strtoll(const char *str, int *toput);
t_bool	put_n_check(char **words, int *toput, int count);

void	merge(int **arr, int start, int mid, int end);
void	merge_recursive(int **arr, int start, int end);
int		*merge_sort(int *temp, int count);

void	sort_two(t_deque *deque);
void	sort_three(t_deque *deque);
void	sort_five(t_deque *a, t_deque *b);
void	sort_big(t_deque *a, t_deque *b);

void	find_my_place_in(t_deque *deque, int me);
void	rotate_until_sorted(t_deque *deque);
void	rotate_toward_nearest(t_deque *deque, int target, int tardex);
void	push_lis_elem(int *lis, t_deque *a, t_deque *b);
void	find_best_friend(t_deque *a, t_deque *b);
void	get_best_pos(int *pos, t_deque *a, t_deque *b, int index);
void	do_pos(int ago, int bgo, t_deque *a, t_deque *b);
void	r_or_rr(t_deque *a, int go, int both);

int		calc_togo(int a, int b);
int		calc_both(int a, int b);
int		get_min(t_deque *deque);
int		get_mindex(t_deque *deque);
int		get_max(t_deque *deque);
int		get_deque_len(t_deque *deque, int top, int bottom);
int		is_next(t_deque *deque, int me);

int		*find_lis(t_deque *deque);
int		*get_lis_seq(t_deque *deque, int *temp, int *stack);
int		*back_trace(t_deque *deque, int *lis, int *temp);
int		put_stack(int cur, int *stack);

#endif
