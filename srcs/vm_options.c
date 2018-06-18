/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:35 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/18 10:50:50 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		search_options(char *option)
{
	if (ft_strcmp(option, "-dump") == 0)
		return (1);
	if (ft_strcmp(option, "--stealth") == 0)
		return (1);
	if (ft_strcmp(option, "-n") == 0)
		return (1);
	if (ft_strcmp(option, "-s") == 0)
		return (1);
	if (ft_strcmp(option, "-v") == 0)
		return (1);
	if (ft_strcmp(option, "-a") == 0)
		return (1);
	if (ft_strcmp(option, "-d") == 0)
		return (1);
	if (ft_strcmp(option, "-b") == 0)
		return (1);
	return (0);
}

int		check_options(char **argv, t_env *env)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (search_options(argv[i]))
			i++;
		else if (ft_create_player(argv[i], env))
			env->nb_players++;
		else
			display_errors("Can't read file\n");
		i++;
	}
	return (1);
}
