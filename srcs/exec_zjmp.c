/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:08:02 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/30 10:45:20 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_zjmp(t_env *env, t_process *process)
{
	char	zjmp[3];
	int		jump;

	if (process->carry == 0)
		return (0);
	ft_bzero(zjmp, 3);
	copy_memory_area(env, zjmp, process->current, 2);
	//ft_printf("zjmp[0] vaut : %x\n", (unsigned char)zjmp[0]);
	//ft_printf("zjmp[1] vaut : %x\n", (unsigned char)zjmp[1]);
	jump = process->current + (zjmp[0] << 8 | zjmp[1]);
	jump = check_adress(jump);
	process->current = jump;
	//ft_printf("jump vaut : %d\n", jump);
	return (1);
}
