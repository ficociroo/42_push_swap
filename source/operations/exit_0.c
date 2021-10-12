/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:58:09 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/11 13:14:13 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	error_exit(void)
{
	write(STDERR_FILENO, ERR_MSG, ft_strlen(ERR_MSG));
	exit(EXIT_FAILURE);
}

void	free_exit(int status, t_stacks *stacks)
{
	t_steps	*tmp;

	while (stacks->step_list != NULL)
	{
		tmp = stacks->step_list->next_step;
		free(stacks->step_list);
		stacks->step_list = tmp;
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	if (status == EXIT_FAILURE)
		error_exit();
	exit(status);
}
