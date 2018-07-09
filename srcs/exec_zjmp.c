/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:08:02 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/09 12:54:55 by sgauguet         ###   ########.fr       */
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
	param.value[0] = jump;
	param.success = (process->carry) ? 1 : 0;
	jump = check_adress(jump);
	show_operations(env, process, &param);
	if (process->carry == 0)
		return (0);
	process->current = jump;
	return (1);
}
