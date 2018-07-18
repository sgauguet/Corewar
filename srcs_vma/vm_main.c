/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:22 by sgauguet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/17 18:21:47 by aserguie         ###   ########.fr       */
=======
/*   Updated: 2018/07/18 17:41:50 by jebossue         ###   ########.fr       */
>>>>>>> 0e0f16a8eba8a5780deeaf5f4eccbc9f6f527c9b
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
	run_the_game(&env);
	debug(&env);
	return (1);
}
