/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:26:33 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/14 03:12:37 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	clean_step(t_stacks *stc, int cmd, int id)
{
	t_steps	*tmp;

	if (cmd == P)
	{
		if (stc->last_step == stc->step_list)
		{
			free(stc->step_list);
			stc->step_list = NULL;
			stc->last_step = NULL;
		}
		else
		{
			tmp = stc->step_list;
			while (tmp->next_step != stc->last_step)
				tmp = tmp->next_step;
			free(stc->last_step);
			stc->last_step = tmp;
			stc->last_step->next_step = NULL;
		}
	}
	else
		stc->last_step->command = cmd + id;
}

void	add_step(t_stacks *stc, int cmd, int id)
{
	t_steps		*new_step;

	if (stc->step_list != NULL)
	{
		if ((stc->last_step->command - (cmd - id)) == 1
			|| (stc->last_step->command - (cmd - id)) == -1)
		{
			clean_step(stc, cmd, STC_R);
			return ;
		}
	}
	new_step = calloc(1, sizeof(t_steps));
	new_step->command = cmd + id;
	if (stc->step_list == NULL)
	{
		stc->step_list = new_step;
		stc->last_step = new_step;
		return ;
	}
	stc->last_step->next_step = new_step;
	stc->last_step = new_step;
}

void	swap(t_stacks *stacks, int stc)
{
	int			tmp;

	tmp = stacks->idx[stc][0];
	stacks->idx[stc][0] = stacks->idx[stc][1];
	stacks->idx[stc][1] = tmp;
	add_step(stacks, S, stc);
}
