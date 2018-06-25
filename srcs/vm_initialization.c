/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:55 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/25 18:05:55 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_constants(void)
{
	if (IND_SIZE != 2 || REG_SIZE != 4 || DIR_SIZE != REG_SIZE || REG_CODE != 1 || DIR_CODE != 2 || IND_CODE != 3 || COMMENT_CHAR != '#' || LABEL_CHAR != ':' || DIRECT_CHAR != '%' || SEPARATOR_CHAR != ',')
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

int		init_instructions(t_env *env)
{
	env->instructions[0] = (t_op){"live", 1, {T_DIR}, 1, 10, "alive", 0, 0};
	env->instructions[1] = (t_op){"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0};
	env->instructions[2] = (t_op){"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0};
	env->instructions[3] = (t_op){"add", 3, {T_REG, T_REG, T_REG},
		4, 10, "addition", 1, 0};
	env->instructions[4] = (t_op){"sub", 3, {T_REG, T_REG, T_REG},
		5, 10, "soustraction", 1, 0};
	env->instructions[5] = (t_op){"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0};
	env->instructions[6] = (t_op){"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0};
	env->instructions[7] = (t_op){"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0};
	env->instructions[8] = (t_op){"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1};
	env->instructions[9] = (t_op){"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10, 25, "load index", 1, 1};
	env->instructions[10] = (t_op){"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11, 25, "store index", 1, 1};
	env->instructions[11] = (t_op){"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1};
	env->instructions[12] = (t_op){"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0};
	env->instructions[13] = (t_op){"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		14, 50, "long load index", 1, 1};
	env->instructions[14] = (t_op){"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1};
	env->instructions[15] = (t_op){"aff", 1, {T_REG}, 16, 2, "aff", 1, 0};
//	env->instructions[16] = (t_op){0, 0, {0}, 0, 0, 0, 0, 0};
	return (1);
}

int		init_vm_champions(t_env *env)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		env->champions[i].player_id = i + 1;
		ft_bzero(env->champions[i].file, 50);
		env->champions[i].header.magic = 0;
		ft_bzero(env->champions[i].header.prog_name, PROG_NAME_LENGTH + 1);
		env->champions[i].header.prog_size = 0;
		ft_bzero(env->champions[i].header.comment, COMMENT_LENGTH + 1);
		ft_bzero(env->champions[i].instructions, CHAMP_MAX_SIZE);
		env->champions[i].nb_lives = 0;
		i++;
	}
	return (1);
}

int		init_vm_environment(t_env *env)
{
	int	i;

	i = 0;
	//check_constants();
	ft_bzero(env->arena, MEM_SIZE);
	env->cycle_to_die = CYCLE_TO_DIE;
	env->nb_players = 0;
	while (i != 16)
	{
		ft_bzero(env->instructions[i].name, 6);
		ft_bzero(env->instructions[i].description, 36);
		env->instructions[i].params[0] = 0;
		env->instructions[i].params[1] = 0;
		env->instructions[i].params[2] = 0;
		i++;
	}
	init_vm_champions(env);
	init_instructions(env);
	return (1);
}
