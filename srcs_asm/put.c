/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:03:30 by tpacaly           #+#    #+#             */
/*   Updated: 2018/08/20 18:24:29 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_put(char *str, char c, char fd, char bool_free)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
	(c != 0) ? write(fd, &c, 1) : 0;
	(bool_free == 1) ? ft_strdel(&str) : 0;
}
