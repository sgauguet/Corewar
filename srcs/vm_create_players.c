/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:30 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/21 17:39:55 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_header_player(char *buf, t_env *env)
{
	char			magic[4];
	char			prog_size[4];
	unsigned int	check_magic;
	int				mod_padding;

	check_magic = COREWAR_EXEC_MAGIC;
	ft_memcpy(magic, buf, 4);
	if ((magic[1] << 16 & 0xff0000) == (check_magic & 0xff0000) && (magic[2] << 8 & 0x00ff00) == (check_magic & 0x00ff00) && (magic[3] & 0x0000ff) == (check_magic & 0x0000ff))
		env->champions[env->nb_players].header.magic = COREWAR_EXEC_MAGIC;
	ft_memcpy(env->champions[env->nb_players].header.prog_name, &buf[sizeof(((header_t*)0)->magic)], PROG_NAME_LENGTH);
	mod_padding = (sizeof(((header_t*)0)->prog_name) % 4) ? (4 - (sizeof(((header_t*)0)->prog_name) % 4)) : 0;
	ft_memcpy(prog_size, &buf[sizeof(((header_t*)0)->magic) + sizeof(((header_t*)0)->prog_name) + mod_padding], 4);
	//if (prog_size[1] + prog_size[2] + prog_size[3] != //retour de read - header)
	//	display_errors("prog_size != size instructions");
	printf("decalage prog_size : %d\n", prog_size[1] << 16 & 0xff0000);
	printf("decalage prog_size : %d\n", prog_size[2] << 8 & 0x00ff00);
	printf("prog_size : %d\n", prog_size[3] & 0x0000ff);
	ft_memcpy(env->champions[env->nb_players].header.comment, &buf[sizeof(((header_t*)0)->magic) + sizeof(((header_t*)0)->prog_name) + sizeof(((header_t*)0)->prog_size) + mod_padding], COMMENT_LENGTH);
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
