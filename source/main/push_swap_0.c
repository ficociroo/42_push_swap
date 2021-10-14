/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 09:29:15 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/14 01:32:06 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stacks	*c_stacks_values(int intc)
{
	t_stacks	*address;

	address = calloc(1, sizeof(t_stacks));
	if (address == NULL)
		return (NULL);
	address->val[0] = calloc((intc + 1), sizeof(int));
	if (address->val[0] == NULL)
	{
		free(address);
		return (NULL);
	}
	address->val[1] = calloc((intc + 1), sizeof(int));
	if (address->val[1] == NULL)
	{
		free(address->val[0]);
		free(address);
		return (NULL);
	}
	address->qty[0] = intc - 1;
	address->qty[1] = -1;
	return (address);
}

static void	sort_small_stack(t_stacks *stc)
{
	if (stc->idx[0][0] == 0)
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
	else
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

void	sig_bit_array(t_stacks *stc)
{
	int		i;

	i = 0;
	while (i <= stc->qty[0])
	{
		stc->val[0][i] = sig_bit_counter(stc->idx[0][i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	stacks = c_stacks_values(argc - 1);
	if (!stacks)
		error_exit();
	if (parse_arg(argc, argv, stacks) == FALSE)
		free_exit(EXIT_FAILURE, stacks);
	if (check_sort_val(stacks) == FALSE)
	{
		sort_array(stacks);
		sig_bit_array(stacks);
		if (stacks->qty[0] == 2)
			sort_small_stack(stacks);
		else
			sort_stacks(stacks);
	}
	if (stacks->step_list != NULL)
		print_steps(stacks->step_list);
	end_free_exit(EXIT_SUCCESS, stacks);
}
