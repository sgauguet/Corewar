/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:08:52 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/04 13:01:59 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_lfork(t_env *env, t_process *process)
{
	char	dest[2];
	t_fork	lfork;

	ft_bzero(dest, 2);
	copy_memory_area(env, dest, check_adress(process->current), 2);
	lfork.pc = check_adress(dest[0] << 8 | dest[1]);
	lfork.carry = process->carry;
	lfork.alive = process->alive;
	create_process(env, process->reg, process->current, &lfork);
	return (0);
}
