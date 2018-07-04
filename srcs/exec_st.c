/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:07:44 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/04 12:53:13 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_st(t_env *env, t_process *process)
{
	char	reg_value[4];
	char	dest[2];
	int		adress;
	int		param_size;

	if (!copy_register(process, reg_value,
				(int)env->arena[check_adress(process->current + 2)]))
		return (0);
	if (process->ocp[0] != 1 || ((param_size = process->ocp[1]) != 1
		&& param_size != 3))
		return (0);
	param_size = (param_size == 3) ? param_size - 1 : param_size;
	ft_bzero(dest, 2);
	copy_memory_area(env, dest, check_adress(process->current + 2), param_size);
	adress = (param_size == 2) ? (dest[0] << 8 | dest[1]) % IDX_MOD
		: dest[0] % IDX_MOD;
	adress = check_adress(adress + process->current);
	modify_memory_content(env, reg_value, adress, 4);
	process->carry = 1;
	return (1);
}
