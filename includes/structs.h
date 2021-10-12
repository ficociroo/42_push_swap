/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:23:42 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/12 16:55:22 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_steps
{
	int				command;
	struct s_steps	*next_step;
}				t_steps;

typedef struct s_stacks
{
	int				*a;
	int				*b;
	int				a_qty;
	int				b_qty;
	t_steps			*step_list;
	t_steps			*last_step;
}				t_stacks;

#endif
