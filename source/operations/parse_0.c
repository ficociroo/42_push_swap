/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:58:09 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/12 19:12:43 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_arg_digit(const char *arg)
{
	int			i;
	int			has_digit;

	has_digit = FALSE;
	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i] != '\0')
	{
		if (!(ft_isdigit(arg[i])))
			return (FALSE);
		has_digit = TRUE;
		i++;
	}
	if (has_digit == FALSE)
		return (FALSE);
	return (TRUE);
}

static int	check_repeated(int value, int i, int *stack)
{
	while (--i >= 0)
		if (stack[i] == value)
			return (FALSE);
	return (TRUE);
}

int	parse_arg(int argc, char *argv[], t_stacks *stacks)
{
	int			i;
	double		d_value;

	i = 0;
	while (i < argc - 1)
	{
		if (check_arg_digit(argv[i + 1]) == FALSE)
			return (FALSE);
		d_value = ft_atod(argv[i + 1]);
		if (d_value > INT_MAX || d_value < INT_MIN)
			return (FALSE);
		stacks->val[0][i] = (int)d_value;
		if (check_repeated(stacks->val[0][i], i, stacks->val[0]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
