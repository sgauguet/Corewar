/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:35 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/25 15:27:31 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		search_options(t_env *env, char **argv, int argc, int i)
{
	int ret;
	int check;

	//Pour les flags prenant un param numerique, verifier les bornes (j'ai une fonction toute prete dans mon push_swap)

	ret = 0;
	check = ((i + 1) < argc) ? 1 : 0;
	if (ft_strlen(argv[i]) < 1 || argv[i][0] != '-')
		return (0);
	if (!ft_strcmp(argv[i], "-a") && (ret = 1))
		env->option.a = 1;
	else if ((!ft_strcmp(argv[i], "-d") || !ft_strcmp(argv[i], "-dump"))
			&& check && (ret = 2))
		env->option.d = ft_atoi(argv[i + 1]);
	else if (!ft_strcmp(argv[i], "-s") && check && (ret = 2))
		env->option.s = ft_atoi(argv[i + 1]);
	else if (!ft_strcmp(argv[i], "-v") && check && (ret = 2))
		env->option.v = ft_atoi(argv[i + 1]);
	else if (!ft_strcmp(argv[i], "-b") && (ret = 1))
		env->option.b = 1;
	else if (!ft_strcmp(argv[i], "-n") && (ret = 1))
		env->option.n = 1;
	else if (!ft_strcmp(argv[i], "--stealth") && (ret = 1))
		env->option.stealth = 1;
	if (ret)
		return (ret);
	return (0);
}

int		check_options(char **argv, int argc, t_env *env)
{
	int	i;
	int	ret;

	i = 1;
	while (argv[i])
	{
		if (!(ret = search_options(env, argv, argc, i)))
			create_player(argv[i], env);
		else if (ret == 2)
			i++;
		i++;
	}
	return (1);
}
