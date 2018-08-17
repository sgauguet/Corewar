/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:08:52 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/22 19:48:55 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_lfork(t_env *env, t_process *process)
{
	char	dest[2];
	t_param param;
	t_fork	lfork;

	ft_bzero(dest, 2);
	copy_memory_area(env, dest, check_adress(process->current), 2);
	param.value[0] = (dest[0] << 8) | (unsigned char)dest[1];
	param.adress = param.value[0] + process->current;
	lfork.pc = check_adress(param.adress);
	lfork.carry = process->carry;
	lfork.alive = process->alive;
	lfork.last = process->last;
	lfork.col_pair = process->col_pair % UNDER_LINE;
	create_process(env, process->reg, process->current, &lfork);
	if (env->option.visu)
	{
	env->arena2[check_adress(process->current)] += (env->arena2[check_adress(process->current)] < STAND_OUT) ? STAND_OUT : 0;
	display_ncurses(env, process, check_adress(process->current), 1);
	}
	if (env->option.v == 4 || env->option.v < 0)
		show_operations(env, process, &param);
	return (1);
}
