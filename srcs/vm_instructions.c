/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 10:27:58 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/28 14:18:05 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_instruction(t_env *env, t_process *process)
{
	if (process && env)
		return (1);
	return (0);
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
