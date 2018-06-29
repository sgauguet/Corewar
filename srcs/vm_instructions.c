/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 10:27:58 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/29 18:13:14 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		size_param(t_env *env, t_process *process)
{
	int i;
	int instruction;
	int result;

	i = 0;
	result = 2;
	instruction = (int)(process->opcode);
	while (i < 3)
	{
		if (process->ocp[i] == 1)
			result++;
		else if (process->ocp[i] == 3)
			result = result + 2;
		else if (process->ocp[i] == 2)
			result += (env->instructions[instruction].direct_size == 1) ? 2 : 4;
		i++;
	}
	return (result);
}

int     check_ocp(t_env *env, t_process *process)
{
	int		ocp;
	int     result;

	ft_printf("ocp : %c\n", env->arena[process->current + 1]);
	ocp = (unsigned int)env->arena[process->current + 1] / 4;
	process->ocp[2] = ocp % 4;
	ocp = ocp / 4;
	process->ocp[1] = ocp % 4;
	ocp = ocp / 4;
	process->ocp[0] = ocp % 4;
	/*ft_printf("Parametre 1 : %d\n", process->ocp[0]);
	ft_printf("Parametre 2 : %d\n", process->ocp[1]);
	ft_printf("Parametre 3 : %d\n", process->ocp[2]);*/
	result = size_param(env, process);
	ft_printf("result : %d\n", result);
	return (result);
}

int		nb_cycles_instruction(t_env *env, t_process *process)
{
	int				opcode;

	opcode = (int)process->opcode;
	if (opcode < 1 || opcode > NB_INSTRUCTIONS)
		return (1);
	return (env->instructions[opcode - 1].nb_cycles);
}

int		exec_instruction(t_env *env, t_process *process)
{
	if (env && process)
		return (0);
	return (1);
}

int		size_instruction(t_env *env, t_process *process)
{
	int opcode;

	opcode = (int)process->opcode;
	//ft_printf("op : %d\n", opcode);
	if (process->cycle_before_exec == 1)
		return (1);
	else if (opcode == 9 || opcode == 12 || opcode == 15)
		return (3);
	else if (opcode == 1)
		return (5);
	else
		return (check_ocp(env, process));
}
