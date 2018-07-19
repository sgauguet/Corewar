/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:47:39 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/18 22:26:32 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	new->id = env->process.process_id;
	new->current = start_position;
	new->opcode = env->arena[start_position];
	new->pc = (fork) ? fork->pc : start_position;
	new->cycle_before_exec = 0;
	new->carry = (fork) ? fork->carry : 0;
	new->alive = (fork) ? fork->alive : 0;
	new->last = 0;
	new->next = env->process.first_process;
	env->process.first_process = new;
	if (fork)
		new_instruction(env, new);
	env->process.process_id++;
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
		reg[0] = -1 * env->champions[i].player_id;
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
