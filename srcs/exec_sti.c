/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:07:44 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/30 12:00:43 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int        exec_sti(t_env *env, t_process *process)
{
	char	reg_value[4];
	char	param1[2];
	char	param2[2];
	int		adress;
	int		param1_size;
	int		param2_size;

	if (!copy_register(process, reg_value, (int)env->arena[check_adress(process->current + 2)]))
		return (0);
	if (process->ocp[0] != 1 || ((param1_size = process->ocp[1]) != 1 && param1_size != 3) || ((param2_size  = process->ocp[2]) != 1 && param2_size != 3))
		return (0);
	param1_size = (param1_size == 3) ? param1_size - 1 : param1_size; 
	param2_size = (param2_size == 3) ? param2_size - 1 : param2_size; 
	ft_bzero(param1, 2);
	ft_bzero(param2, 2);
	copy_memory_area(env, param1, check_adress(process->current + 2), param1_size);
	copy_memory_area(env, param2, check_adress(process->current + 2 + param1_size), param2_size);
	adress = (param1_size == 2) ? (param1[0] << 8 | param1[1]) : param1[0];
	adress += (param2_size = 2) ? (param2[0] << 8 | param2[1]) : param2[0];
	modify_memory_content(env, reg_value, adress, 4);
	/*ft_printf("param1_size vaut : %d\n", param1_size);
	ft_printf("param2_size vaut : %d\n", param2_size);
	ft_printf("adress vaut : %d\n", adress);
	ft_printf("reg[0] : %x\n", (unsigned char)reg_value[0]);
	ft_printf("reg[1] : %x\n", (unsigned char)reg_value[1]);
	ft_printf("reg[2] : %x\n", (unsigned char)reg_value[2]);
	ft_printf("reg[3] : %x\n", (unsigned char)reg_value[3]);*/
    return (1);
}
