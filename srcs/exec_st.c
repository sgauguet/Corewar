/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:07:44 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/10 12:04:13 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_st(t_env *env, t_process *process)
{
	char	reg_value[4];
	char	tmp[2];
	t_param param;

	if (process->ocp[0] != 1 || ((process->ocp[1]) != 1 && process->ocp[1] != 3))
		return (0);
	param.value[0] = (int)env->arena[check_adress(process->current + 2)];
	if (!copy_register(process, reg_value, param.value[0]) 
			|| !params_size_ocp(env, process, &param))
		return (0);
	copy_memory_area(env, tmp, check_adress(process->current + 2), param.size[1]);
	param.value[1] = (param.size[1] == 2) ? (tmp[0] << 8 | (unsigned char)tmp[1]) : tmp[0];
	param.adress = check_adress(param.value[1] % IDX_MOD + process->current);
	ft_printf("val : %d, adress : %d\n", param.value[0], param.adress);
	modify_memory_content(env, reg_value, param.adress, 4);
	process->carry = 1;
	show_operations(env, process, &param);
	return (1);
}
