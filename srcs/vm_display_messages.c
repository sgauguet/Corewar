/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_display_messages.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 09:45:35 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/09 10:22:30 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		show_operations(t_env *env, t_process *process, t_param *param)
{
	int i;

	i = 0;
	if ((int)process->opcode < 1 || (int)process->opcode > NB_INSTRUCTIONS)
		return (0);
	ft_printf("P %4d | %s", process->id, env->instructions[(int)(process->opcode) - 1].name);
	while (i < 3)
	{
		if (process->ocp[i])
			(process->ocp[i] == 1) ? ft_printf(" r%d", param->value[i]) 
				: ft_printf(" %d", param->value[i]);
		i++;
	}
	if ((int)process->opcode == 11)
		ft_printf("\n       | -> store to %d + %d = %d (with pc and mod %d)", param->value[1],
			param->value[2], param->value[1] + param->value[2], param->adress);
	if ((int)process->opcode == 1 || (int)process->opcode == 9 || (int)process->opcode == 12
			|| (int)process->opcode == 15)
		ft_printf(" %d", param->value[0]);
	if ((int)process->opcode == 9)
		(param->success == 1) ? ft_printf(" OK") : ft_printf(" FAILED");
	if ((int)process->opcode == 12 || (int)process->opcode == 15)
		ft_printf(" (%d)", param->adress);
	ft_printf("\n");
	return (1);
}

int		show_deaths(t_env *env, t_process *process)
{
	ft_printf("Process %lu hasn't lived for %d cycles (CTD %d)\n", process->id,
			process->alive, env->cycle_to_die);
	return (1);
}

int		show_pc_movements(t_env *env, t_process *process)
{
	int	op;
	int size;
	
	op = (int)process->opcode;
	size = 1;
	size += (op == 1 || op == 9 || op == 12 || op == 15) ? 0 : 1;
	size += process->ocp[0] + process->ocp[1] + process->ocp[2];
	if (size == 1)
		return (0);
	ft_printf("ADV %d ", size);
	(process->current) ? ft_printf("(%#06x -> ", check_adress(process->current))
		: ft_printf("(0x0000 -> ");
	(process->pc) ? ft_printf("%#06x) ", check_adress(process->pc))
		: ft_printf("0x0000) ");
	display_specific_area(env, (int)process->current, size);
	ft_printf("\n");
	return (1);
}

int		display_end(t_env *env)
{	
	int i;

	i = 0;
	ft_printf("Contestant %d, \"%s\", has won !\n", env->champions[i].player_id,
			env->champions[i].header.prog_name); 
	return (1);
}

int		display_start(t_env *env)
{
	int i;

	i = 0;
	while (ft_strlen(env->champions[i].file))
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", 
			env->champions[i].player_id, env->champions[i].header.prog_size,
			env->champions[i].header.prog_name, env->champions[i].header.comment);
		i++;
	}
	return (1);
}
