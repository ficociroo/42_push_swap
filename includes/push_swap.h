/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:25:04 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/12 15:10:37 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** ~*~*~*~*~*~*~*~ HEADERS ~*~*~*~*~*~*~*~
*/

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft/libft.h"
# include "structs.h"

/*
** ~*~*~*~*~*~*~*~ MACROS ~*~*~*~*~*~*~*~
*/

# define ERR_MSG		"Error\n"

# define TRUE			1
# define FALSE			0

# define SA				0
# define SB				1
# define SS				2
# define PA				3
# define PB				4
# define RA				5
# define RB				6
# define RR				7
# define RRA			8
# define RRB			9
# define RRR			10

/*
** ~*~*~*~*~*~*~*~ FUNCTION PROTOTYPES ~*~*~*~*~*~*~*~
*/
/*
** ~*~*~*~ MAIN ~*~*~*~
*/
/*
** push_swap_0.c
*/

/*
** ~*~*~*~ OPERATIONS ~*~*~*~
*/

/*
** check_sorted_0.c
*/
int			check_sorted(int *stack_a, int a_qty);

/*
** exit_0.c
*/
void		error_exit(void);
void		free_exit(int status, t_stacks *stacks);

/*
** parse_0.c
*/
int			parse_arg(int argc, char *argv[], t_stacks *stacks);

/*
** print_steps_0.c
*/
void		print_steps(t_steps *step_list);

/*
** sort_stacks_0.c
*/
void		sort_stacks(t_stacks *stacks);

#endif
