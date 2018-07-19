/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:22:41 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/19 16:11:18 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_options(t_env *env)
{
	if (env->option.v == 2 || env->option.v < 0)
		ft_printf("It is now cycle : %d\n", env->cycle);
	if (env->option.d && env->option.d == env->cycle)
		display_arena(env);
	return (1);
}

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
	int cycle_consumed;

	cycle_consumed = 0;
	display_start(env);
	while (env->process.nb_process)
	{
		if (cycle_consumed == env->cycle_to_die)// || cycle_consumed == MAX_CHECKS)
		{
			search_dead_process(env);
			cycle_consumed = 0;
			if (env->nb_live_env >= NBR_LIVE)
			{
				env->nb_live_env = 0;
				env->cycle_to_die -= (env->cycle_to_die >= CYCLE_DELTA)
					? CYCLE_DELTA : (env->cycle_to_die - 1);
			}
		}
		exec_process(env);
		if (!env)
			ft_printf("It is now cycle : %d\n", env->cycle);
		exec_options(env);
		env->cycle++;
		cycle_consumed++;
	}
	display_end(env);
	return (1);
}
