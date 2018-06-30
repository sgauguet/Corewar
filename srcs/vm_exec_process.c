/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:22:41 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/30 10:18:07 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_process(t_env *env)
{
	t_process *process;

	process = env->process.first_process;
	while (process)
	{
		if (process->cycle_before_exec == 0)
			new_instruction(env, process);
		if (process->cycle_before_exec == 1)
		   exec_instruction(env, process);
		process->cycle_before_exec--;
		process = process->next;
	}
	return (1);
}

int		run_the_game(t_env *env)
{
	int cycle_to_die;

	cycle_to_die = 0;
	ft_printf("start of the game\n");
	while (env->process.nb_process)
	{
		if (cycle_to_die == env->cycle_to_die)
		{
			search_dead_process(env);
			cycle_to_die = 0;
		}
		exec_process(env);
		env->cycle++;
		cycle_to_die++;
	}
	ft_printf("end of the game cycle : %d\n", env->cycle - 1);
	return (1);
}
