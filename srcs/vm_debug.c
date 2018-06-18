/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:45:43 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/18 17:35:24 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_initialization(t_env *env)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%u", (unsigned int)&env->arena[i]);
		i++;
	}
	return (1);
}

int		debug(t_env *env)
{
	//check_initialization(env);
	if (env)
		;
	return (1);
}
