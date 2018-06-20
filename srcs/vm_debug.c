/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:45:43 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/20 10:01:04 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_initialization(t_env *env)
{
	int i;

	i = 0;
	display_arena(env);
	return (1);
}

int		debug(t_env *env)
{
	if (env)
		;
	check_initialization(env);
	return (1);
}
