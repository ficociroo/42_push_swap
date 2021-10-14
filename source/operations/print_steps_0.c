/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:58:09 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/13 22:49:18 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	write_hub(int command)
{
	int		cmd;
	int		stc;

	cmd = command / 10;
	stc = command % 10;
	if (cmd == 1)
	{
		write(STDOUT_FILENO, "s", 1);
		if (stc == 2)
			write(STDOUT_FILENO, "s\n", 2);
	}
	else if (cmd == 2)
		write(STDOUT_FILENO, "p", 1);
	else if (cmd == 3)
		write(STDOUT_FILENO, "r", 1);
	else if (cmd == 4)
		write(STDOUT_FILENO, "rr", 2);
	if (stc == 0)
		write(STDOUT_FILENO, "a\n", 2);
	if (stc == 1)
		write(STDOUT_FILENO, "b\n", 2);
	if (stc == 2 && cmd != 1)
		write(STDOUT_FILENO, "r\n", 2);
}

void	print_steps(t_steps *step_list)
{
	t_steps		*print_step;

	print_step = step_list;
	while (print_step != NULL)
	{
		write_hub(print_step->command);
		print_step = print_step->next_step;
	}
}
