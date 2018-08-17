/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:08:02 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/17 16:48:42 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_zjmp(t_env *env, t_process *process)
{
	char	zjmp[2];
	t_param	param;
	int		jump;

	ft_bzero(zjmp, 2);
	copy_memory_area(env, zjmp, process->current, 2);
	jump = zjmp[0] << 8 | (unsigned char)zjmp[1];
//	ft_printf("jump = %d\n jump% = %d", jump, jump % IDX_MOD);
	param.value[0] = jump;
	param.success = (process->carry) ? 1 : 0;
	jump = check_adress(process->current + jump % IDX_MOD);
	if (env->option.v == 4 || env->option.v < 0)
		show_operations(env, process, &param);
	//process->prev_col = env->arena2[process->current] % UNDER_LINE;//((mvinch(process->pc / 64 + 1, 3 * (process->pc % 64)) & A_COLOR) / 256);
	if (process->carry == 0)
		return (0);
	process->pc = jump;
	//process->prev_col = env->arena2[jump] % UNDER_LINE;
	return (1);
}
