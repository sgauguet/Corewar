/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:08:52 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/30 09:09:00 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int        exec_lfork(t_env *env, t_process *process)
{
    char dest[2];
	int lfork_pc;

	ft_bzero(dest, 2);
	copy_memory_area(env, dest, check_adress(process->current), 2);
	lfork_pc = check_adress(dest[0] << 8 | dest[1]);
	create_process(env, process->reg, process->current, lfork_pc);
	//ft_printf("process créé a l'adresse %d\n", lfork_pc);
    return (0);
}
