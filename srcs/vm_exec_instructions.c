/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 11:50:53 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/04 12:48:29 by sgauguet         ###   ########.fr       */
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

int		exec_instruction(t_env *env, t_process *process)
{
	if ((int)(process->opcode) == 3)
		exec_st(env, process);
	if ((int)(process->opcode) == 9)
		exec_zjmp(env, process);
	if ((int)(process->opcode) == 11)
		exec_sti(env, process);
	if ((int)(process->opcode) == 12)
		exec_fork(env, process);
	if ((int)(process->opcode) == 16)
		exec_aff(env, process);
	return (1);
}
