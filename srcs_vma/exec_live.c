/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:03:08 by aserguie          #+#    #+#             */
/*   Updated: 2018/07/18 18:28:13 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_live(t_env *env, t_process *process)
{
	char	tmp[4];
	t_param param;

	if (process->ocp[0] != 0)
		return (0);
	if (!params_size_ocp(env, process, &param))
		return (0);
	copy_memory_area(env, tmp, check_adress(process->current), 4);
	param.value[0] = (tmp[0] << 24 | (unsigned char)tmp[1] << 16
			| (unsigned char)tmp[2] << 8 | (unsigned char)tmp[3]);
	if (param.value[0] >= env->nb_players || param.value[0] <= 0)
		return (0);
	process->alive = 1;
	((env->champions[param.value[0]]).nb_lives) += 1;
	show_operations(env, process, &param);
	return (1);
}
