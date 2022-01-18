/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:44:25 by hakim             #+#    #+#             */
/*   Updated: 2022/01/14 00:44:31 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_typo(const char *input)
{
	int	index;

	index = 0;
	if (input[index] == '\0')
		return (FALSE);
	while (9 <= input[index] && input[index] <= 13)
		++index;
	if (input[index] == '-' || input[index] == '+')
		++index;
	while (input[index] != '\0')
	{
		if (ft_isdigit(input[index]) == 0)
			return (FALSE);
		++index;
	}
	return (TRUE);
}

t_bool	check_dup(const int *temp, int count)
{
	int	index;

	if (temp == 0)
		return (FALSE);
	index = 0;
	while (index < count)
	{
		if (temp[index] == temp[count])
			return (FALSE);
		++index;
	}
	return (TRUE);
}

static int	check_space(const char *str)
{
	int	index;

	index = 0;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	return (index);
}

t_bool	ps_strtoll(const char *str, int *toput)
{
	long long	result;
	int			plma;
	int			index;
	int			len;

	index = check_space(str);
	plma = 1;
	len = 0;
	if (str[index] == '-')
		plma = -1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	result = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + str[index] - '0';
		index++;
		len++;
	}
	result *= plma;
	if (len > 10 || result > 2147483647 || result < -2147483648)
		return (FALSE);
	*toput = (int)result;
	return (TRUE);
}

int	*ft_free_split(char **splitted)
{
	int	index;

	index = 0;
	while (splitted[index] != 0)
		++index;
	--index;
	while (index >= 0)
	{
		free(splitted[index]);
		splitted[index] = 0;
		--index;
	}
	free(splitted);
	splitted = 0;
	return (0);
}
