/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:33:19 by jebossue          #+#    #+#             */
/*   Updated: 2018/07/18 16:32:22 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	and_param(t_env *env, t_process *process, t_param *param, int i)
{
	char	tmp[4];
	int		head;

	if (i == 1)
		head = process->current + 1 + param->size[0];
	else
		head = process->current + 1;
	copy_memory_area(env, tmp, check_adress(head), param->size[i]);
	if (param->size[i] == 1)
	{
		copy_register(process, param->param[i], (int)tmp[0]);
		param->value[i] = register_value(process, (int)tmp[0]);
	}
	else if (param->size[i] == 4)
	{
		copy_memory_area(env, param->param[i], head, 4);
		param->value[i] = param->param[i][0] << 24 | param->param[i][1] << 16 |
			param->param[i][2] << 8 | param->param[i][3];
	}
	else if (param->size[i] == 2)
	{
		copy_memory_area(env, param->param[i], ((int)tmp[0]) - 1, 2);
		printf("pos : %d", ((int)tmp[0]) - 1);
		param->value[i] = param->param[i][0] << 8 | param->param[i][1];
	}
	return (1);
}

int	check_and(t_env *env, t_process *process, t_param *param)
{
	if ((process->ocp[0] != 1 && process->ocp[0] != 2 && process->ocp[0] != 3)
		|| (process->ocp[1] != 1 && process->ocp[1] != 2 && process->ocp[1] != 3)
		|| process->ocp[2] != 1)
		return (0);
	if (!params_size_ocp(env, process, param))
		return (0);
	param->value[2] = (int)env->arena[check_adress(process->current + 2
			+ param->size[0] + param->size[1])];
	if (param->value[2] < 1 || param->value[2] > NB_INSTRUCTIONS)
		return (0);
	return (1);
}



int	exec_and(t_env *env, t_process *process)
{
	t_param	param;
	char	result[4];

	if (!check_and(env, process, &param))
		return (0);
	if (!and_param(env, process, &param, 0))
		return (0);
	if (!and_param(env, process, &param, 1))
		return (0);
	result[0] = param.param[0][0] & param.param[1][0];
	result[1] = param.param[0][1] & param.param[1][1];
	result[2] = param.param[0][2] & param.param[1][2];
	result[3] = param.param[0][3] & param.param[1][3];
	modify_register_content(process, result, param.value[2]);
	show_operations(env, process, &param);
	return (1);
}
