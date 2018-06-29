/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 10:27:58 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/28 14:46:27 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_instruction(t_env *env, t_process *process)
{
	int				opcode;
	char			ocp;

	opcode = (int)process->opcode;
	if (opcode < 1 || opcode > NB_INSTRUCTIONS)
		return (0);
	ocp = env->arena[process->current + 1];
	ft_printf("ocp : %x\n", ocp);
	return (1);
}

int		exec_instruction(t_env *env, t_process *process)
{
	if (!check_instruction(env, process))
		return (0);
	return (1);
}

int		instruction_size(t_env *env, t_process *process)
{
	int opcode;

	opcode = (int)process->opcode;
	if (!env)
		return (-1);
	if (process->cycle_before_exec == -1)
		return (0);
	if (opcode == 1 || opcode == 5 || opcode == 6)
		return (5);
	if (opcode == 9 || opcode == 12 || opcode == 15 || opcode == 16)
	   return (3);
	return (10);
}

int		search_instruction(t_env *env, char opcode)
{
	int	op;

	op = (int)opcode;
	if (env)
		return (0);
	return (1);
}
