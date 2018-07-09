/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_display_messages.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 09:45:35 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/05 12:04:30 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		show_deaths(t_env *env, t_process *process)
{
	if (env && process)
		return (0);
	// Ajouter un ID par process pour l'affichage
	//ft_printf("Process %d hasn't lived for %d cycles ((CTD %d)\n",
	//			process->id, process->alive, env->cycle_to_die);
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
