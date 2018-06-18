/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:22 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/18 10:52:41 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_env	env;
	int		i;

	if (argc < 2)
		display_usage(argv);
	init_vm_environment(argv, &env);
	i = 0;
	while (i < 3)
	{
		ft_printf("%s\n", env.champions[i]);
		i++;
	}
	ft_printf("%d\n", env.nb_players);
	return (1);
}
