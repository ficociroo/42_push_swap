/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:26:33 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/14 01:47:47 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	advance_stc(int *stc, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		stc[i] = stc[i + 1];
		i++;
	}
	stc[size] = 0;
}

static void	revolve_stc(int *stc, int size)
{
	int			i;

	i = size + 1;
	while (i > 0)
	{
		stc[i] = stc[i - 1];
		i--;
	}
	stc[0] = 0;
}

void	rot(t_stacks *stacks, int stc)
{
	int			tmp;

	if (stacks->qty[stc] <= 0)
		return ;
	tmp = stacks->idx[stc][0];
	advance_stc(stacks->idx[stc], stacks->qty[stc]);
	stacks->idx[stc][stacks->qty[stc]] = tmp;
	add_step(stacks, R, stc);
}

void	rev_rot(t_stacks *stacks, int stc)
{
	if (stacks->qty[stc] <= 0)
		return ;
	revolve_stc(stacks->idx[stc], stacks->qty[stc]);
	stacks->idx[stc][0] = stacks->idx[stc][stacks->qty[stc] + 1];
	stacks->idx[stc][stacks->qty[stc] + 1] = 0;
	add_step(stacks, RR, stc);
}

void	push(t_stacks *stacks, int stc)
{
	int			other_stc;
	int			tmp;

	other_stc = STC_A;
	if (other_stc == stc)
		other_stc = STC_B;
	tmp = stacks->idx[other_stc][0];
	advance_stc(stacks->idx[other_stc], stacks->qty[other_stc]);
	revolve_stc(stacks->idx[stc], stacks->qty[stc]);
	stacks->idx[stc][0] = tmp;
	stacks->qty[stc]++;
	stacks->qty[other_stc]--;
	add_step(stacks, P, stc);
}
