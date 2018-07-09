/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_destroy_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 09:34:57 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/28 14:05:53 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		destroy_process(t_env *env, t_process *process)
{
	t_process *tmp;

	if ((tmp = env->process.first_process) == NULL)
		return (0);
	if (tmp == process)
	{
		env->process.first_process = process->next;
		ft_memdel((void **)&process);
		return (1);
	}
	while (tmp->next != process && tmp->next)
		tmp = tmp->next;
	if (tmp->next == process)
	{
		tmp->next = process->next;
		ft_memdel((void **)&process);
		return (1);
	}
	return (0);
}

int		search_dead_process(t_env *env)
{
	t_process *process;
	t_process *tmp;

	process = env->process.first_process;
	while (process)
	{
		if (process->alive == 0)
		{
			tmp = process->next;
			if (destroy_process(env, process))
				env->process.nb_process--;
			process = tmp;
		}
		else
		{
			process->alive = 0;
			process = process->next;
		}
	}
	return (1);
}
