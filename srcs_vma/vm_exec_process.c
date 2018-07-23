/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:22:41 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/23 20:07:57 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_options(t_env *env)
{
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
	int check;

	cycle_consumed = 0;
	check = 0;
	display_start(env);
	while (env->process.nb_process)
	{
		if (cycle_consumed >= env->cycle_to_die)
		{
			check++;
			search_dead_process(env);
			cycle_consumed = 0;
			if (env->nb_live_env >= NBR_LIVE || check == MAX_CHECKS)
			{
				check = 0;
				env->cycle_to_die -= CYCLE_DELTA;
				if (env->option.v == 2 || env->option.v < 0)
					ft_printf("Cycle to die is now %d\n", env->cycle_to_die);
			}
				env->nb_live_env = 0;
		}
		if ((env->option.v == 2 || env->option.v < 0) && env->process.nb_process)
			ft_printf("It is now cycle %d\n", env->cycle);
//		ft_printf("total live %d\nchecks %d\n", env->nb_live_env, check);
		exec_process(env);
		exec_options(env);
		env->cycle++;
		cycle_consumed++;
	}
	display_end(env);
	return (1);
}
