/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:58:09 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/14 01:39:51 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	bit_boolean(int value, int bitshifter)
{
	return (value & (1 << bitshifter));
}

int	sig_bit_counter(int value)
{
	int		counter;
	int		bit_bool;

	counter = (sizeof(int) * 8) - 1;
	while (counter >= 0)
	{
		bit_bool = bit_boolean(value, counter);
		if (bit_bool)
			break ;
		counter--;
	}
	counter++;
	return (counter);
}

static void	sort_bit_array(t_stacks *stacks, int bit_id)
{
	int		i;
	int		cycles;
	int		bit_bool;

	i = 0;
	cycles = stacks->qty[0];
	while (i <= cycles)
	{
		bit_bool = bit_boolean(stacks->idx[0][0], bit_id);
		if (!bit_bool)
		{
			push(stacks, STC_B);
/* 			if (i > stacks->val[1][0] && i != cycles)
				rot(stacks, STC_B); */
		}
		else
			rot(stacks, STC_A);
		i++;
	}
}

/* static void	bring_sorted_b(t_stacks *stacks)
{
	while (stacks->qty[1] >= 0)
	{
		rev_rot(stacks, STC_B);
		push(stacks, STC_A);
	}
} */

void	sort_stacks(t_stacks *stacks)
{
	int		sig_bit;
	int		i;

	i = 0;
	sig_bit = sig_bit_counter(stacks->qty[0]);
	while (i < sig_bit)
	{
		sort_bit_array(stacks, i);
		while (stacks->qty[1] >= 0 && stacks->val[1][0] < i)
			push(stacks, STC_A);
		i++;
	}
//	bring_sorted_b(stacks);
}
