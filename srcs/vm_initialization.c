/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:55 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/18 12:14:02 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_constants(void)
{
	if (IND_SIZE != 2 || REG_SIZE != 4 || DIR_SIZE != REG_SIZE || REG_CODE != 1 || DIR_CODE != 2 || IND_CODE != 3 || COMMENT_CHAR != '#' || LABEL_CHAR != ':' || DIRECT_CHAR != '%' || SEPARATOR_CHAR != ',' || LABEL_CHARS != "abcdefghijklmnopqrstuvwxyz_0123456789" || NAME_CMD_STRING != ".name" || COMMENT_CMD_STRING ".comment")
		display_errors("");
	if (REG_NUMBER != 16)
		display_errors("");
	if (MAX_ARGS_NUMBER != 4)
		display_errors("");
	if (MAX_PLAYERS != 4)
		display_errors("");
	if (MEM_SIZE != (4*1024))
		display_errors("");
	if (IDX_MOD != (MEM_SIZE / 8))
		display_errors("");
	if (CHAMP_MAX_SIZE != (MEM_SIZE / 6))
		display_errors("");
	if (REG_NUMBER != 16)
		display_errors("");
	if (CYCLE_TO_DIE != 1536)
		display_errors("");
	if (CYCLE_DELTA != 50)
		display_errors("");
	if (NBR_LIVE != 21)
		display_errors("");
	if (MAX_CHECKS != 10)
		display_errors("");
	if (T_REG != 1 || T_DIR != 2 || T_IND != 4 || T_LAB != 8)
		display_errors("");
	if (PROG_NAME_LENGTH != (128) || COMMENT_LENGTH != (2048) || COREWAR_EXEC_MAGIC != 0xea83f3)
		display_errors("");
	return (1);
}

int		init_vm_champions(t_env *env)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		env->champions[i].player_id = i + 1;
		env->champions[i].header.magic = COREWAR_EXEC_MAGIC;
		ft_bzero(env->champions[i].header.prog_name, PROG_NAME_LENGTH + 1);
		env->champions[i].header.prog_size = 0;
		ft_bzero(env->champions[i].header.comment, COMMENT_LENGTH + 1);
		env->champions[i].instructions = NULL;
		env->champions[i].nb_lives = 0;
		i++;
	}
	return (1);
}

int		init_vm_environment(t_env *env)
{
	check_constants();
	ft_bzero(env->arena, MEM_SIZE);
	env->cycle_to_die = CYCLE_TO_DIE;
	env->nb_players = 0;
	init_vm_champions(env);
	return (1);
}
