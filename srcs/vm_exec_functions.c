/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:27:47 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/13 11:24:25 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_adress(int adress)
{
	int result;

	result = adress % MEM_SIZE;
	result = (result < 0) ? (MEM_SIZE + result) : result;
	return (result);
}

int		params_size_ocp(t_env *env, t_process *process, t_param *param)
{
	int	op;
	int	i;

	i = 0;
	if ((op = (int)process->opcode) < 1 || (int)process->opcode > NB_INSTRUCTIONS)
		return (0);
	param->size[0] = process->ocp[0];
	param->size[1] = process->ocp[1];
	param->size[2] = process->ocp[2];
	while (i < 3)
	{
		if (param->size[i] == 2 && env->instructions[op - 1].direct_size == 0)
			param->size[i] += 2;
		if (param->size[i] == 3)
			param->size[i] -= 1;
		i++;
	}
	return (1);
}

int		copy_register(t_process *process, char *buf, int reg_number)
{
	int i;

	i = 0;
	if (reg_number < 1 || reg_number > REG_NUMBER)
		return (0);
	while (i < 4)
	{
		buf[i] = process->reg[reg_number - 1] << (24 - (8 * i));
		i++;
	}
	return (1);
}

int		register_value(t_process *process, int reg_number)
{
	int result;

	if (reg_number < 1 || reg_number > NB_INSTRUCTIONS)
		return (0);
	result = process->reg[reg_number - 1];
	return (result);
}

int		indirect_value(t_env *env, int start)
{
	int		result;
	char	tmp[2];

	copy_memory_area(env, tmp, start - 1, 2);
	result = tmp[0] << 8 | (unsigned char)tmp[1];
	return (result);
}

void	copy_memory_area(t_env *env, char *buf, int start, int size)
{
	int i;
	int pos;

	i = 0;
	pos = start;
	while (i < size)
	{
		pos = check_adress(pos + 1);
		buf[i] = env->arena[pos];
		i++;
	}
}

void	modify_register_content(t_process *process, char *new_value, int reg_number)
{
	int result;

	if (reg_number < 1 || reg_number > NB_INSTRUCTIONS)
		return ;
	result = new_value[0] << 24 | new_value[1] << 16 | new_value[2] << 8 | new_value[3];
	process->reg[reg_number - 1] = result;
}

void	modify_memory_content(t_env *env, char *buf, int start, int size)
{
	int i;
	int pos;

	i = 0;
	pos = start - 1;
	while (i < size)
	{
		pos = check_adress(pos + 1);
		env->arena[pos] = buf[i];
		i++;
	}
}
