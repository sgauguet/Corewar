/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:55 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/18 10:48:49 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		init_vm_environment(char **argv, t_env *env)
{
	env->nb_players = 0;
	env->cycle_to_die = CYCLE_TO_DIE;
	check_options(argv, env);
	return (1);
}
