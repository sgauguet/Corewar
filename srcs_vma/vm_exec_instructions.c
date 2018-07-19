/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 11:50:53 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/19 17:28:21 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	nb_cycles_instruction(t_env *env, t_process *process)
{
	int	opcode;

	opcode = (int)process->opcode;
	if (opcode < 1 || opcode > NB_INSTRUCTIONS)
		return (1);
	return (env->instructions[opcode - 1].nb_cycles);
}

int	new_instruction(t_env *env, t_process *process)
{
	process->current = process->pc;
	process->opcode = env->arena[process->current];
	process->cycle_before_exec = nb_cycles_instruction(env, process);
	process->ocp[0] = 0;
	process->ocp[1] = 0;
	process->ocp[2] = 0;
	process->pc = check_adress(process->current
		+ size_instruction(env, process));
	return (1);
}

int	exec_instruction(t_env *env, t_process *process)
{
	if (env->option.v == 16 || env->option.v < 0)
		show_pc_movements(env, process);
	if ((int)(process->opcode) == 1)
		exec_live(env, process);
	if ((int)(process->opcode) == 2)
		exec_ld(env, process);
	if ((int)(process->opcode) == 3)
		exec_st(env, process);
	if ((int)(process->opcode) == 4)
		exec_add(env, process);
	if ((int)(process->opcode) == 5)
		exec_sub(env, process);
	if ((int)(process->opcode) == 6)
		exec_and(env, process);
	if ((int)(process->opcode) == 7)
		exec_or(env, process);
	if ((int)(process->opcode) == 8)
		exec_xor(env, process);
	if ((int)(process->opcode) == 9)
		exec_zjmp(env, process);
	if ((int)(process->opcode) == 10)
		exec_ldi(env, process);
	if ((int)(process->opcode) == 11)
		exec_sti(env, process);
	if ((int)(process->opcode) == 12)
		exec_fork(env, process);
	if ((int)(process->opcode) == 13)
		exec_lld(env, process);
	if ((int)(process->opcode) == 14)
		exec_lldi(env, process);
	if ((int)(process->opcode) == 15)
		exec_lfork(env, process);
	if ((int)(process->opcode) == 16)
		exec_aff(env, process);
	return (1);
}
