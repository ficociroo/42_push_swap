/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:25:04 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/14 00:27:43 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** ~*~*~*~*~*~*~*~ HEADERS ~*~*~*~*~*~*~*~
*/

# include <limits.h>
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

# define STC_A			0
# define STC_B			1
# define STC_R			2

# define S				10
# define P				20
# define R				30
# define RR				40

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
** DEL_0.c <<<<<<<<<<<<<<<<<<
*/
void		print_stacks(t_stacks *stacks);

/*
** check_sort_0.c
*/
int			check_sort_val(t_stacks *stc);
int			check_sort_idx(t_stacks *stc);

/*
** commands_0.c
*/
void		rot(t_stacks *stacks, int stc);
void		rev_rot(t_stacks *stacks, int stc);
void		push(t_stacks *stacks, int stc);

/*
** commands_1.c
*/
void		add_step(t_stacks *stacks, int cmd, int stc);
void		swap(t_stacks *stacks, int stc);

/*
** exit_0.c
*/
void		error_exit(void);
void		free_exit(int status, t_stacks *stacks);
void		end_free_exit(int status, t_stacks *stacks);

/*
** parse_0.c
*/
int			parse_arg(int argc, char *argv[], t_stacks *stacks);

/*
** print_steps_0.c
*/
void		print_steps(t_steps *step_list);

/*
** sort_array_0.c
*/
void		sort_array(t_stacks *stacks);

/*
** sort_stacks_0.c
*/
int			sig_bit_counter(int value);
void		sort_stacks(t_stacks *stacks);

#endif
