/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:45:33 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/12 18:19:21 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;
	char *buf;
	int ret;

	buf = ft_strnew(1);
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = read(fd, buf, 1)) >= 1)
		{
			ft_printf("%x\n", buf[0]);
		}
	}
	return (1);
}
