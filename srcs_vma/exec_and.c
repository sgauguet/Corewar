/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:33:19 by jebossue          #+#    #+#             */
/*   Updated: 2018/07/17 18:27:57 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	and_param(t_env *env, t_process *process, t_param *param, int i)
{
	/*char	tmp[4];

	copy_memory_area(env, tmp, check_adress(process->current + 1), param->size[i]);
	if (param->size[i] == 1)
	{
		ft_strcpy(param->param[i], (char*)register_value(process, (int)tmp[0])); //if register_value == 0 and good value on reg_number we are fuuck up
	}
	if (param->size[i] == 2)*/
	if (env && process && param && i)
		return (0);
	return (1);
}

int	check_and(t_env *env, t_process *process, t_param *param)
{
	/*if ((process->ocp[0] != 1 && process->ocp[0] != 2 && process->ocp[0] != 3)
		|| (process->ocp[1] != 1 && process->ocp[1] != 2 && process->ocp[1] != 3)
		|| process->ocp[2] != 1)
		return (0);
	if (!params_size_ocp(env, process, param))
		return (0);
	param->value[2] = (int)env->arena[check_adress(process->current + 2
			+ param->size[0] + param->size[1])];
	if (param->value[2] < 1 || param->value[2] > NB_INSTRUCTIONS)
		return (0)*/
	if (env && process && param)
		return (0);
	return (1);
}



int	exec_and(t_env *env, t_process *process)
{
	/*t_param	param;
	char	param1[4];
	char	param2[4];

	if (!check_and(env, process, &param))
		return (0);
	if (!and_param(env, process, &param, 0))
		return (0);
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
	show_operations(env, process, &param);*/
	if (env && process)
		return (0);
	return (1);
}
