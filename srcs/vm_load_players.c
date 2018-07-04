/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_load_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:07 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/04 12:05:37 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		load_players(t_env *env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ft_strlen(env->champions[i].file))
	{
		ft_memcpy(&env->arena[j], env->champions[i].instructions,
				CHAMP_MAX_SIZE);
		j = j + MEM_SIZE / env->nb_players;
		i++;
	}
	return (1);
}
