/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:58:09 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/12 21:06:45 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	c_idx_arrays(t_stacks *stacks)
{
	stacks->idx[0] = calloc(stacks->qty[0] + 2, sizeof(int));
	if (stacks->idx[0] == NULL)
		free_exit(EXIT_FAILURE, stacks);
	stacks->idx[1] = calloc(stacks->qty[0] + 2, sizeof(int));
	if (stacks->idx[1] == NULL)
	{
		free(stacks->idx[0]);
		free_exit(EXIT_FAILURE, stacks);
	}
}

void	sort_array(t_stacks *stacks)
{
	int		i;
	int		i_cmp;

	i = 0;
	c_idx_arrays(stacks);
	while (i <= stacks->qty[0])
	{
		i_cmp = 0;
		while (i_cmp <= stacks->qty[0])
		{
			if (stacks->val[0][i] > stacks->val[0][i_cmp])
				stacks->idx[0][i]++;
			i_cmp++;
		}
		i++;
	}
}
