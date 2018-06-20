/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_display_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 09:17:47 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/20 10:03:32 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		display_memory_area(char byte)
{
	if (byte == '\0')
		ft_printf("00 ");
	else
		ft_printf("%x", byte);
	return (1);
}

int		display_arena(t_env *env)
{
	int i;
	int line;

	i = 0;
	line = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0i && i > 1)
		{
			line++;
			ft_printf("%#06x : ", i);
		}
		display_memory_area(env->arena[i]);
		if ((i + 1) % 64 == 0)
			ft_printf("\n");
		i++;
	}
	ft_printf("%d\n", i);
	return (1);
}
