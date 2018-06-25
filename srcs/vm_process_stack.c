/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:17:19 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/25 18:15:47 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		destroy_process(t_env *env)
{
	(void)env;


	return (1);
}

int		create_process(t_env *env, int *reg, int current)
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
	new->current = current;
	new->opcode = env->arena[current];
	//new->pc = find_pc(); 
	new->next = env->process.first_process;
	env->process.first_process = new;
	return(1);
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
		create_process(env, reg, (MEM_SIZE * i) / env->nb_players);
		i++;
	}


	return (1);
}
