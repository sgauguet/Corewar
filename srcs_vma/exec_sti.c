/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:18:42 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/19 13:17:51 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_sti(t_env *env, t_process *process, t_param *param, char *reg)
{
	if (process->ocp[0] != 1 || (process->ocp[1] < 1 || process->ocp[1] > 3)
		|| ((process->ocp[2] != 1 && process->ocp[2] != 2)))
		return (0);
	param->value[0] = (int)env->arena[check_adress(process->current + 2)];
	if (!copy_register(process, reg, param->value[0])
		|| !params_size_ocp(env, process, param))
		return (0);
	return (1);
}

int		do_sti(t_env *env, t_process *process, t_param *param, char *reg_value)
{
	param->adress = (param->value[1] + param->value[2]) % IDX_MOD
		+ process->current;
	modify_memory_content(env, reg_value, check_adress(param->adress), 4);
	process->carry = 1;
	show_operations(env, process, param);
	return (1);
}

int		exec_sti(t_env *env, t_process *process)
{
	char	reg_value[4];
	char	tmp[4];
	t_param	param;

	if (!check_sti(env, process, &param, reg_value))
		return (0);
	copy_memory_area(env, tmp, check_adress(process->current + 2),
			param.size[1]);
	param.value[1] = (param.size[1] == 2) ? (tmp[0] << 8
		| (unsigned char)tmp[1]) : register_value(process, (int)tmp[0]);
	if (process->ocp[1] == 3)
		param.value[1] = indirect_value(env, param.value[1]);
	if (param.size[1] == 1 && ((int)tmp[0] < 1
		|| (int)tmp[0] > NB_INSTRUCTIONS))
		return (0);
	copy_memory_area(env, tmp, check_adress(process->current + 2
		+ param.size[1]), param.size[2]);
	param.value[2] = (param.size[2] == 2) ? (tmp[0] << 8
		| (unsigned char)tmp[1]) : register_value(process, (int)tmp[0]);
	if (param.size[2] == 1 && ((int)tmp[0] < 1
		|| (int)tmp[0] > NB_INSTRUCTIONS))
		return (0);
	return (do_sti(env, process, &param, reg_value));
}
