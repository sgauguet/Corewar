/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:22 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/19 13:11:39 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		display_usage(argv);
	init_vm_environment(&env);
	check_options(argv, &env);
	load_players(&env);
	init_process_stack(&env);
	env.last_alive = &env.champions[0];
	debug(&env);
	run_the_game(&env);
	//debug(&env);
	return (1);
}
