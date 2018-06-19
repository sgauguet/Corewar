/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:30 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/19 18:45:46 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_header_player(char *buf, t_env *env)
{
	unsigned char	magic[4];
	unsigned char	prog_size[4];
	int	i;
	int	mod_padding;

	i = 4;
	if (env)
		;
	ft_memcpy(magic, buf, 4);
//	ft_printf("%#x\n", (unsigned int)magic); //marche pO 
//	Check size name
	ft_memcpy(env->champions[env->nb_players].header.prog_name, &buf[sizeof(((header_t*)0)->magic)], PROG_NAME_LENGTH);
	printf("%s\n", env->champions[env->nb_players].header.prog_name);
	mod_padding = (sizeof(((header_t*)0)->prog_name) % 4) ? (4 - (sizeof(((header_t*)0)->prog_name) % 4)) : 0;
	ft_memcpy(prog_size, &buf[sizeof(((header_t*)0)->magic) + sizeof(((header_t*)0)->prog_name) + mod_padding], 4);
	printf("%u\n", (unsigned int)prog_size);
	ft_memcpy(env->champions[env->nb_players].header.comment, &buf[sizeof(((header_t*)0)->magic) + sizeof(((header_t*)0)->prog_name) + sizeof(((header_t*)0)->prog_size) + mod_padding], COMMENT_LENGTH);
	printf("%s\n", env->champions[env->nb_players].header.comment);

	return (1);
}

int	ft_create_player(char *file, t_env *env)
{
	int		fd;
	char	buf[sizeof(header_t)];
	int		ret;

	ft_bzero(buf, sizeof(header_t));
	if ((fd = open(file, O_RDONLY)) < 1 || read(fd, buf, 0) == -1)
		return (0);
	if ((ret = read(fd, buf, sizeof(header_t))) != sizeof(header_t))
	{
		ft_printf("%d\n", sizeof(header_t));
		display_errors("Can't read header < sizeof(header)\n");
	}
	if (!ft_header_player(buf, env))
		display_errors("Problem init header player\n");
		//read instructions;
	env->nb_players++;
	return (1);
}
