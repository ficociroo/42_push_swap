/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:58:09 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/13 21:12:19 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_sort_val(t_stacks *stc)
{
	int		i;

	if (stc->qty[1] != -1)
		return (FALSE);
	i = stc->qty[0];
	while ((i - 1) >= 0)
	{
		if (stc->val[0][i - 1] > stc->val[0][i])
			return (FALSE);
		i--;
	}
	return (TRUE);
}

int	check_sort_idx(t_stacks *stc)
{
	int		i;

	if (stc->qty[1] != -1)
		return (FALSE);
	i = stc->qty[0];
	while ((i - 1) >= 0)
	{
		if (stc->idx[0][i - 1] > stc->idx[0][i])
			return (FALSE);
		i--;
	}
	return (TRUE);
}
