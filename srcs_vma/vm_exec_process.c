/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:22:41 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/25 17:59:35 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_options(t_env *env)
{
	char c;

	c = '0';

	//quel comportement si -d et -s sont actives? on prend le premier des deux? le plus petit?...

	if (env->option.d != -1 && env->option.d == env->cycle - 1)
	{
		display_arena(env);
		//free les process et eventuellement l'arene
	}
	if (env->option.s != -1 && (/*(env->cycle == 1) ||*/ ((env->cycle - 1) % env->option.s == 0)))
	{
		display_arena(env);
		while (c != '\n')
		{
			read(0, &c, 1);
		}
	}

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
	int	delta = 0;

	cycle_consumed = 0;
	check = 0;
	display_start(env);
	exec_options(env);
	while (env->process.nb_process && cycle_consumed >= 0)
	{
/*		ft_printf("to die %d\nconsumed %d\nalive %d\nlast %d\nlive_env %d\nnb_process %d\n", env->cycle_to_die, cycle_consumed, env->process.first_process->alive, env->process.first_process->last, env->nb_live_env, env->process.nb_process);*/
		if (cycle_consumed >= env->cycle_to_die)
		{
			check++;
			search_dead_process(env);
			cycle_consumed = 0;
			if (env->nb_live_env >= NBR_LIVE || check == MAX_CHECKS)
			{
				check = 0;
				delta = 1;
				env->cycle_to_die -= CYCLE_DELTA;
			}
				env->nb_live_env = 0;
		}

//		ft_printf("consumed2 %d\n", cycle_consumed);

		if (delta && (env->option.v == 2 || env->option.v < 0))
		{
			delta = 0;
			ft_printf("Cycle to die is now %d\n", env->cycle_to_die);
		}

		if (env->cycle != 1)
			exec_options(env);
		if ((env->option.v == 2 || env->option.v < 0) && env->process.nb_process)
			ft_printf("It is now cycle %d\n", env->cycle);

		exec_process(env);
//		if (cycle_consumed >= env->cycle_to_die && env->process.nb_process)
//			search_dead_process(env);
		env->cycle++;
		cycle_consumed++;
	}
//	(env->cycle_to_die > -15 || ((env->process.nb_process != 0) && env->process.first_process->alive < cycle_consumed)))
	display_end(env);
	return (1);
}
