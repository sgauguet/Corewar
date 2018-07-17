/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:33:19 by jebossue          #+#    #+#             */
/*   Updated: 2018/07/17 15:43:20 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	check_and(t_env *env, t_process *process, t_param *param, char *reg)
{
	if ((process->ocp[0] != 1 && process->ocp[0] != 2 && process->ocp[0] != 3)
		|| (process->ocp[1] != 1 && process->ocp[1] != 2 && process->ocp[1] != 3)
		|| process->ocp[2] != 1)
		return (0);
	if (!params_size_ocp(env, process, param))
		return (0);
	param->value[2] = (int)env->arena[check_adress(process->current + 2
			+ param->size[0] + param->size[1])];
	if (!copy_register(process, reg, param->value[2]))
		return (0);
	return (1);
}

int	exec_and(t_env *env, t_process *process)
{
	t_param	param;
	char	reg_value[4];
	char	tmp[4];

	if (!check_and(env, process, &param, reg_value))
		return (0);
	copy_memory_area(env, tmp, check_adress(process->current + 2), param.size[0]);
	if (param.size[0] == 1 && ((int)tmp[0] < 1 || (int)tmp[0] > NB_INSTRUCTIONS))
			return (0);
	param.value[0] = (param.size[0] == 2) ? (tmp[0] << 8 | (unsigned char)tmp[1]) : register_value(process, (int)tmp[0]);
	if (process->ocp[0] == 3)
		param.value[0] = indirect_value(env, param.value[0]);
	copy_memory_area(env, tmp, check_adress(process->current + 2 + param.size[0]), param.size[1]);
	if (param.size[1] == 1 && ((int)tmp[0] < 1 || (int)tmp[0] > NB_INSTRUCTIONS))
		return (0);
	param.value[1] = (param.size[1] == 2) ? (tmp[0] << 8 | (unsigned char)tmp[1]) : register_value(process, (int)tmp[0]);
	if (process->ocp[1] == 3)
		param.value[1] = indirect_value(env, param.value[1]);

	return (1);
}
