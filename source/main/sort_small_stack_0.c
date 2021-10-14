/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:31:49 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/14 04:14:58 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_three_stack(t_stacks *stc)
{
	if (stc->idx[0][0] == 0 && stc->idx[0][1] != 1)
	{
		swap(stc, STC_A);
		rot(stc, STC_A);
	}
	else if (stc->idx[0][0] == 1)
	{
		if (stc->idx[0][1] == 0)
			swap(stc, STC_A);
		else
			rev_rot(stc, STC_A);
	}
	else if (stc->idx[0][0] == 2)
	{
		if (stc->idx[0][1] == 0)
			rot(stc, STC_A);
		else
		{
			swap(stc, STC_A);
			rev_rot(stc, STC_A);
		}
	}
}

void	sort_small_stack(t_stacks *stc)
{
	int		i;

	while (stc->qty[STC_A] > 2)
	{
		i = 0;
		while (stc->idx[STC_A][i] != stc->qty[STC_A])
			i++;
		if (i == 0)
			push(stc, STC_B);
		else if (i > stc->qty[STC_A] / 2)
			rev_rot(stc, STC_A);
		else
			rot(stc, STC_A);
	}
	sort_three_stack(stc);
	while (stc->qty[STC_B] >= 0)
	{
		push(stc, STC_A);
		rot(stc, STC_A);
	}
}
