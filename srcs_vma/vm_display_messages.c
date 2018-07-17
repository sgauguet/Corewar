/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_display_messages.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 09:45:35 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/17 10:30:27 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_usage(char **argv)
{
	ft_printf("Usage: %s [-d N -s N -v N | -b --stealth | --stealth ]"
	"| -n --stealth] [-a] <champion1.cor> <...>\n"
	"\t-a        : Prints output from \"aff\" (Default is to hide it)\n"
	"#### TEXT OUTPUT MODE #################################################\n"
	"\t-d N      : Dumps memory after N cycles then exits\n"
	"\t-s N      : Runs N cycles, dumps memory, pauses, then repeats\n"
	"\t-v N      : Verbosity levels, can be added together to enable several\n"
	"\t\t- 0 : Show only essentials\n"
	"\t\t- 1 : Show lives\n"
	"\t\t- 2 : Show cycles\n"
	"\t\t- 4 : Show operations (Params are NOT litteral ...)\n"
	"\t\t- 8 : Show deaths\n"
	"\t\t- 16 : Show PC movements (Except for jumps)\n"
	"#### BINARY OUTPUT MODE ###############################################\n"
	"\t-b        : Binary output mode for corewar.42.fr\n"
	"\t--stealth : Hides the real contents of the memory\n"
	"#### NCURSES OUTPUT MODE ##############################################\n"
	"\t-n        : Ncurses output mode\n"
	"\t--stealth : Hides the real contents of the memory\n"
	"#######################################################################\n",
	argv[0]);
	exit(0);
}

int		display_end(t_env *env)
{
	int i;

	i = 0;
	ft_printf("Contestant %d, \"%s\", has won !\n", env->champions[i].player_id,
			env->champions[i].header.prog_name);
	return (1);
}

int		display_start(t_env *env)
{
	int i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (ft_strlen(env->champions[i].file))
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			env->champions[i].player_id, env->champions[i].header.prog_size,
			env->champions[i].header.prog_name,
			env->champions[i].header.comment);
		i++;
	}
	return (1);
}
