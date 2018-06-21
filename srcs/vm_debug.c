/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:45:43 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/21 17:40:02 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		display_champions(t_env *env)
{
	int i;

	i = 0;
	while (env->champions[i].header.magic != 0)
	{
		ft_printf("Player : %d\nHeader => magic : %d, prog_name : %s, prog_size : %d, comment : %s\n", env->champions[i].player_id, env->champions[i].header.magic, env->champions[i].header.prog_name, env->champions[i].header.prog_size, env->champions[i].header.comment);
		i++;
	}
	return (1);
}

int		display_instructions(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (i < 16)
	{
		j = -1;
		ft_printf("name : \"%s\", number : %d params :", env->instructions[i].name, env->instructions[i].number);
		while (j++ < 2)
		   ft_printf(" %d", env->instructions[i].params[j]);
		ft_printf(" opcode : %x, nb_cycles : %d, description \"%s\", modify_carry %d, direct_size %d.\n", env->instructions[i].op_code, env->instructions[i].nb_cycles, env->instructions[i].description, env->instructions[i].modify_carry, env->instructions[i].direct_size);
		i++;
	}
	return (1);
}

int		check_initialization(t_env *env)
{
	if (env)
		;
//	display_instructions(env);
	//display_champions(env);
	//display_arena(env);
	return (1);
}

int		debug(t_env *env)
{
	check_initialization(env);
	return (1);
}
