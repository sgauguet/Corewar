/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:03:08 by aserguie          #+#    #+#             */
/*   Updated: 2018/07/18 22:18:41 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_live(t_env *env, t_process *process)
{
	char	tmp[4];
	t_param param;

	copy_memory_area(env, tmp, check_adress(process->current), 4);
	param.value[0] = (tmp[0] << 24 | (unsigned char)tmp[1] << 16
			| (unsigned char)tmp[2] << 8 | (unsigned char)tmp[3]);
//	ft_printf("%d\n",param.value[0]);
//	ft_printf("nb %d\n", env->nb_players);
	if (param.value[0] >= (-1 * env->nb_players) && param.value[0] < 0)
	{
		process->alive = 1;
		process->last = env->cycle;
		env->champions[-1 * param.value[0] - 1].nb_lives += 1;
		env->last_alive = &env->champions[-1 * param.value[0] - 1];
//		ft_printf("par.val %d\n", param.value[0]);
	}
//	else
//		ft_printf("live %d\n", ((env->champions[-1 * param.value[0] - 1]).nb_lives));
	env->nb_live_env += 1;
//	ft_printf("live %d\n", ((env->champions[-1 * param.value[0] - 1]).nb_lives));
	show_operations(env, process, &param);
	return (1);
}
