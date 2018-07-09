/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:18:42 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/04 12:48:03 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_sti(t_env *env, t_process *process)
{
	char	reg_value[4];
	char	param[2];
	int		adress;
	int		param1_size;
	int		param2_size;

	if (!copy_register(process, reg_value,
		(int)env->arena[check_adress(process->current + 2)])
		|| (process->ocp[0] != 1 || ((param1_size = process->ocp[1]) < 1
		|| param1_size > 3) || ((param2_size = process->ocp[2]) != 1
		&& param2_size != 2)))
		return (0);
	param1_size = (param1_size == 3) ? param1_size - 1 : param1_size;
	param2_size = (param2_size == 3) ? param2_size - 1 : param2_size;
	copy_memory_area(env, param, check_adress(process->current + 2),
		param1_size);
	adress = (param1_size == 2) ? (param[0] << 8 | param[1]) : param[0];
	copy_memory_area(env, param, check_adress(process->current + 2 +
		param1_size), param2_size);
	adress += (param2_size = 2) ? (param[0] << 8 | param[1]) : param[0];
	adress = check_adress(adress % IDX_MOD + process->current);
	modify_memory_content(env, reg_value, adress, 4);
	process->carry = 1;
	return (1);
}
