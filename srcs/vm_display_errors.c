/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_display_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:43 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/05 10:43:12 by sgauguet         ###   ########.fr       */
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

void	display_errors_with_value(int value, int code, t_env *env)
{
	if (code == 0)
		ft_printf("Can't read source file %s\n",
				env->champions[env->nb_players].file);
	if (code == 1)
		ft_printf("Error: File %s has too large a code (%d bytes > %lu "
			"bytes).\n", env->champions[env->nb_players].file,
			value, CHAMP_MAX_SIZE);
	exit(0);
}

void	display_errors(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(0);
}
