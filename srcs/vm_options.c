/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:35 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/05 10:39:06 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		search_options(char *option)
{
	int ret;

	ret = 0;
	if (ft_strlen(option) < 1 || option[0] != '-')
		return (0);
	if (!ft_strcmp(option, "-n") && (ret = 1))
		;
	else if (!ft_strcmp(option, "-s") && (ret = 1))
		;
	else if (!ft_strcmp(option, "-v") && (ret = 1))
		;
	else if (!ft_strcmp(option, "-a") && (ret = 1))
		;
	else if (!ft_strcmp(option, "-d") && (ret = 1))
		;
	else if (!ft_strcmp(option, "-b") && (ret = 1))
		;
	if (!ft_strcmp(option, "-dump") && (ret = 1))
		;
	else if (!ft_strcmp(option, "--stealth") && (ret = 1))
		;
	if (ret)
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
			;
		else
			ft_create_player(argv[i], env);
		i++;
	}
	return (1);
}
