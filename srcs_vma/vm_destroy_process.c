#include "corewar.h"

int		free_memory(t_env *env, t_process *process)
{
	if (env->option.v == 8 || env->option.v < 0)
		show_deaths(env, process);
	ft_memdel((void **)&process);
	return (1);
}

int		destroy_process(t_env *env, t_process *process)
{
	t_process *tmp;

	if ((tmp = env->process.first_process) == NULL)
		return (0);
	if (tmp == process)
	{
		env->process.first_process = process->next;
		free_memory(env, process);
		return (1);
	}
	while (tmp->next != process && tmp->next)
		tmp = tmp->next;
	if (tmp->next == process)
	{
		tmp->next = process->next;
		free_memory(env, process);
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
