/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:45:33 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/14 17:19:43 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>


void	display_error(int nb)
{
	if (nb == 1)
		ft_printf("Can't read file\n");
	exit (0);
}

int	ft_check_arguments(char **argv, t_env *env)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-dump") == 0)
			;
		else if (ft_strcmp(argv[i], "--stealth") == 0)
			;
		else if (ft_strcmp(argv[i], "-n") == 0)
			;
		else if (ft_strcmp(argv[i], "-s") == 0)
			i++;
		else if (ft_strcmp(argv[i], "-v") == 0)
			i++;
		else if (ft_strcmp(argv[i], "-a") == 0)
			;
		else if (ft_strcmp(argv[i], "-d") == 0)
			i++;
		else if (ft_strcmp(argv[i], "-b") == 0)
			;
		else if (ft_create_player(argv[i], env))
			env->nb_players++;
		else 
			display_error(1);
		i++;
	}
	return (1);
}

int	ft_init_env(char **argv, t_env *env)
{
	env->nb_players = 0;
	env->cycle_to_die = CYCLE_TO_DIE;
	ft_check_arguments(argv, env);
	return (1);
}

int main(int argc, char **argv)
{
	t_env	env;
	int 	i;

	if (argc > 1)
		ft_init_env(argv, &env);
	i = 0;
	while (i < 3)
	{
		ft_printf("%s\n", env.champions[i]);
		i++;
	}
	ft_printf("%d\n", env.nb_players);
	return (1);
}
