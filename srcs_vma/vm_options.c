/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:35 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/18 21:33:12 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		search_options(t_env *env, char *option)
{
	int ret;

	(void)env;
	ret = 0;
	if (ft_strlen(option) < 1 || option[0] != '-')
		return (0);
	if (!ft_strcmp(option, "-a") && (ret = 1))
		;
	else if (!ft_strcmp(option, "-d") && (ret = 1))
		;
	else if (!ft_strcmp(option, "-s") && (ret = 1))
		;
	else if (!ft_strcmp(option, "-v") && (ret = 1))
		;
	else if (!ft_strcmp(option, "-b") && (ret = 1))
		;
	else if (!ft_strcmp(option, "-n") && (ret = 1))
		;
	else if (!ft_strcmp(option, "--stealth") && (ret = 1))
		;
	if (!ft_strcmp(option, "-dump") && (ret = 1))
		;
	if (ret)
		return (1);
	return (0);
}

int		check_options(char **argv, t_env *env)
{
	int	i;

	i = 1;
//	while (argv[i])
//	{
//		search_options(env, argv[i]);
//		i++;
//	}
	create_player(argv[i], env);
	return (1);
}
