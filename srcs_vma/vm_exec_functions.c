/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:27:47 by sgauguet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/19 18:27:52 by aserguie         ###   ########.fr       */
=======
/*   Updated: 2018/07/20 11:52:34 by jebossue         ###   ########.fr       */
>>>>>>> 8da25f1a0fd21882f1ce314e6afc0cd987ef0634
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
	char	tmp[4];

	//ft_printf("start : %d\n", start);
	copy_memory_area(env, tmp, start - 1, 4);
	result = tmp[0] << 24 | (unsigned char)tmp[1] << 16
		| (unsigned char)tmp[2] << 8 | (unsigned char)tmp[3];
	return (result);
}
