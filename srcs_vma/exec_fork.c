/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:08:34 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/25 16:13:58 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_fork(t_env *env, t_process *process)
{
	char	dest[2];
	t_param param;
	t_fork	fork;

	ft_bzero(dest, 2);
	copy_memory_area(env, dest, check_adress(process->current), 2);
	param.value[0] = (dest[0] << 8) | (unsigned char)dest[1];
	param.adress = (param.value[0] % IDX_MOD + process->current);
	fork.pc = check_adress(param.adress);
	fork.carry = process->carry;
	fork.alive = process->alive;
	fork.last = process->last;
	create_process(env, process->reg, process->current, &fork);
	if (env->option.v == 4 || env->option.v < 0)
		show_operations(env, process, &param);
	return (1);
}
