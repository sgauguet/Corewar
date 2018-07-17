/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:27:47 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/17 10:05:14 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_adress(int adress)
{
	int result;

	result = adress % MEM_SIZE;
	result = (result < 0) ? (MEM_SIZE + result) : result;
	return (result);
}

int		register_value(t_process *process, int reg_number)
{
	int result;

	if (reg_number < 1 || reg_number > NB_INSTRUCTIONS)
		return (0);
	result = process->reg[reg_number - 1];
	return (result);
}

int		indirect_value(t_env *env, int start)
{
	int		result;
	char	tmp[2];

	copy_memory_area(env, tmp, start - 1, 2);
	result = tmp[0] << 8 | (unsigned char)tmp[1];
	return (result);
}
