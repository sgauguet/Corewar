/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 17:24:38 by jebossue          #+#    #+#             */
/*   Updated: 2018/07/19 17:26:13 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	xor_param2(t_env *env, t_process *process, t_param *param, int i)
{
	char	tmp[4];
	int		head;
	int		head2param;
	
	head = (i == 1) ? (process->current + 1 + param->size[0]) :
		(process->current + 1);
	copy_memory_area(env, tmp, check_adress(head), param->size[i]);
	if (param->size[i] == 4)
	{
		copy_memory_area(env, param->param[i], head, 4);
		param->value[i] = param->param[i][0] << 24 | param->param[i][1] << 16 |
			param->param[i][2] << 8 | param->param[i][3];
	}
	else if (param->size[i] == 2)
	{
		head2param = tmp[0] << 8 | (unsigned char)tmp[1];
		copy_memory_area(env, param->param[i], head2param + process->current, 4);
		param->value[i] = indirect_value(env, head2param + process->current);
	}
	return (1);
}

int	xor_param(t_env *env, t_process *process, t_param *param, int i)
{
	char	tmp[4];
	int		head;
	int		j;

	j = 0;
	if (i == 1)
		head = process->current + 1 + param->size[0];
	else
		head = process->current + 1;
	copy_memory_area(env, tmp, check_adress(head), param->size[i]);
	if (param->size[i] == 1)
	{
		copy_register(process, param->param[i], (int)tmp[0]);
		param->value[i] = register_value(process, (int)tmp[0]);
		while (j < 4)
		{
			param->param[i][j] = param->value[i] >> (24 - (8 * i));
			j++;
		}
	}
	return (xor_param2(env, process, param, i));
}

int	check_xor(t_env *env, t_process *process, t_param *param)
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

int	exec_xor(t_env *env, t_process *process)
{
	t_param	param;
	int		i;
	char	result[4];

	i = 0;
	if (!check_xor(env, process, &param))
		return (0);
	if (!xor_param(env, process, &param, 0))
		return (0);
	if (!xor_param(env, process, &param, 1))
		return (0);
	while (i < 4)
	{
		result[i] = param.param[0][i] ^ param.param[1][i];
		i++;
	}
	modify_register_content(process, result, param.value[2]);
	show_operations(env, process, &param);
	return (1);
}
