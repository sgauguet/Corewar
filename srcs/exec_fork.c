/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:08:34 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/04 13:00:58 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_fork(t_env *env, t_process *process)
{
	char	dest[2];
	t_fork	fork;

	ft_bzero(dest, 2);
	copy_memory_area(env, dest, check_adress(process->current), 2);
	fork.pc = check_adress((dest[0] << 8 | dest[1]) % IDX_MOD);
	fork.carry = process->carry;
	fork.alive = process->alive;
	create_process(env, process->reg, process->current, &fork);
	return (1);
}
