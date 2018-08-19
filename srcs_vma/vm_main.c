/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:22 by sgauguet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/08/19 20:09:57 by aserguie         ###   ########.fr       */
=======
/*   Updated: 2018/08/19 16:15:29 by sgauguet         ###   ########.fr       */
>>>>>>> 539577d8bfe9a427b65d268c1ce428c3e1952378
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		display_usage(argv);
	init_vm_environment(&env);
	check_options(argv, argc, &env);
	load_players(&env);
	if (env.option.visu)
		ft_init_visu(&env);
	init_process_stack(&env);
	env.last_alive = &env.champions[env.nb_players - 1];
	run_the_game(&env, 0, 0, 0);
	return (1);
}
