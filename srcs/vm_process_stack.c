/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:17:19 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/05 11:36:56 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		new_instruction(t_env *env, t_process *process)
{
	process->current = process->pc;
	process->opcode = env->arena[process->current];
	process->cycle_before_exec = nb_cycles_instruction(env, process);
	process->ocp[0] = 0;
	process->ocp[1] = 0;
	process->ocp[2] = 0;
	process->pc = (process->current + size_instruction(env, process))
		% MEM_SIZE;
	return (1);
}

int		create_process(t_env *env, int *reg, int start_position, t_fork *fork)
{
	t_process	*new;
	int			i;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		display_errors("Error : process memory not allocated.");
	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = reg[i];
		i++;
	}
	new->current = start_position;
	new->opcode = env->arena[start_position];
	new->pc = (fork) ? fork->pc : start_position;
	new->cycle_before_exec = 0;
	new->carry = (fork) ? fork->carry : 0;
	new->alive = (fork) ? fork->alive : 0;
	new->next = env->process.first_process;
	env->process.first_process = new;
	if (fork)
		new_instruction(env, new);
	env->process.nb_process++;
	return (1);
}

int		init_process_stack(t_env *env)
{
	int		reg[REG_NUMBER];
	int		i;
	int		j;

	i = 0;
	while (ft_strlen(env->champions[i].file))
	{
		reg[0] = env->champions[i].player_id;
		j = 1;
		while (j < REG_NUMBER)
		{
			reg[j] = 0;
			j++;
		}
		create_process(env, reg, (MEM_SIZE * i) / env->nb_players, 0);
		i++;
	}
	return (1);
}
