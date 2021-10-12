/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:58:09 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/11 13:08:31 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	write_hub(int command)
{
	if (command == SA)
		write(STDOUT_FILENO, "sa\n", 3);
	if (command == SB)
		write(STDOUT_FILENO, "sb\n", 3);
	if (command == SS)
		write(STDOUT_FILENO, "ss\n", 3);
	if (command == PA)
		write(STDOUT_FILENO, "pa\n", 3);
	if (command == PB)
		write(STDOUT_FILENO, "pb\n", 3);
	if (command == RA)
		write(STDOUT_FILENO, "ra\n", 3);
	if (command == RB)
		write(STDOUT_FILENO, "rb\n", 3);
	if (command == RR)
		write(STDOUT_FILENO, "rr\n", 3);
	if (command == RRA)
		write(STDOUT_FILENO, "rra\n", 4);
	if (command == RRB)
		write(STDOUT_FILENO, "rrb\n", 4);
	if (command == RRR)
		write(STDOUT_FILENO, "rrr\n", 4);
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
