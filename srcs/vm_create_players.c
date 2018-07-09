/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:30 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/04 12:08:29 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_player_instructions(char *buf, t_env *env)
{
	ft_memcpy(env->champions[env->nb_players].instructions, buf,
			env->champions[env->nb_players].header.prog_size);
	return (1);
}

int	ft_header_player(char *buf, t_env *env)
{
	char			magic[4];
	char			prog_size[4];
	int				mod_padding;

	ft_memcpy(magic, buf, 4);
	check_magic(magic, env);
	ft_memcpy(env->champions[env->nb_players].header.prog_name,
		&buf[sizeof(((header_t*)0)->magic)], PROG_NAME_LENGTH);
	mod_padding = (sizeof(((header_t*)0)->prog_name) % 4) ?
		(4 - (sizeof(((header_t*)0)->prog_name) % 4)) : 0;
	ft_memcpy(prog_size, &buf[sizeof(((header_t*)0)->magic)
		+ sizeof(((header_t*)0)->prog_name) + mod_padding], 4);
	check_prog_size(prog_size, env);
	ft_memcpy(env->champions[env->nb_players].header.comment,
		&buf[sizeof(((header_t*)0)->magic) + sizeof(((header_t*)0)->prog_name)
		+ sizeof(((header_t*)0)->prog_size) + mod_padding], COMMENT_LENGTH);
	return (1);
}

int	ft_create_player(char *file, t_env *env)
{
	int		fd;
	char	buf[sizeof(header_t)];
	int		ret;

	ft_bzero(buf, sizeof(header_t));
	ft_memcpy(env->champions[env->nb_players].file, file,
			(ft_strlen(file) > 50 ? 50 : ft_strlen(file)));
	if ((fd = open(file, O_RDONLY)) < 1 || read(fd, buf, 0) == -1)
		display_errors_with_value(0, 0, env);
	if ((ret = read(fd, buf, sizeof(header_t))) != sizeof(header_t))
	{
		ft_printf("File %s ", file);
		display_errors("is too small to be a champion");
	}
	ft_header_player(buf, env);
	if ((ret = read(fd, buf, CHAMP_MAX_SIZE)) !=
			(int)env->champions[env->nb_players].header.prog_size)
		display_errors("Error prog_size != instructions size");
	ft_player_instructions(buf, env);
	if ((ret = read(fd, buf, 1)))
		display_errors((ret < 0) ? "Read error" : "File too big");
	env->nb_players++;
	if ((ret = close(fd)) == -1)
		display_errors("Close error.");
	return (1);
}
