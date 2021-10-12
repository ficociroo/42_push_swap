/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 09:29:15 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/12 16:56:35 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stacks	*c_stacks(int argc)
{
	t_stacks	*address;

	address = calloc(1, sizeof(t_stacks));
	if (address == NULL)
		return (NULL);
	address->a = calloc((argc - 1), sizeof(int));
	if (address->a == NULL)
	{
		free(address);
		return (NULL);
	}
	address->b = calloc((argc - 1), sizeof(int));
	if (address->b == NULL)
	{
		free(address->a);
		free(address);
		return (NULL);
	}
	address->a_qty = argc - 2;
	return (address);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	stacks = c_stacks(argc);
	if (!stacks)
		error_exit();
	if (parse_arg(argc, argv, stacks) == FALSE)
		free_exit(EXIT_FAILURE, stacks);
	if (check_sorted(stacks->a, stacks->a_qty) == FALSE)
		sort_stacks(stacks);
	if (stacks->step_list != NULL)
		print_steps(stacks->step_list); //free nos steps
	free_exit(EXIT_SUCCESS, stacks);
}
