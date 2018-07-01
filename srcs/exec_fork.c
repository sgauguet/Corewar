/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:08:34 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/30 09:08:45 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int        exec_fork(t_env *env, t_process *process)
{
	char dest[2];
	int fork_pc;
	
	ft_bzero(dest, 2);
	copy_memory_area(env, dest, check_adress(process->current), 2);
	fork_pc = check_adress((dest[0] << 8 | dest[1]) % IDX_MOD);
	create_process(env, process->reg, process-> current, fork_pc);
	//ft_printf("process crée a l'adresse %d\n", fork_pc);
    return (0);
}
