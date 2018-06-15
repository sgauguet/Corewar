/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:27:01 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/14 17:27:02 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_create_player(char *file, t_env *env)
{
	int fd;
	char buf[1];
	int ret;
	char *str;
	int i;

	if (env->nb_players >= 4)
		return (0);
	if ((fd = open(file, O_RDONLY)) < 1 || read(fd, buf, 0) == -1)
		return (0);
	str = ft_strnew(128 + 2048 + CHAMP_MAX_SIZE);
	i = 0;
	while ((ret = read(fd, buf, 1)) == 1 && i < 128 + 2048 + CHAMP_MAX_SIZE)
	{
		str[i] = buf[0];
		i++;
	}
	env->champions[env->nb_players] = str;
	return (1);
}
