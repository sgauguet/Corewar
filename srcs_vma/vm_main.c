/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:22 by sgauguet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/17 18:09:03 by aserguie         ###   ########.fr       */
=======
/*   Updated: 2018/07/17 16:35:19 by jebossue         ###   ########.fr       */
>>>>>>> 182e39c2563a359b7e9c4d318d35382fd434dbb2
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
	//debug(&env);
	return (1);
}
