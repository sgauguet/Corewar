/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:53:01 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/25 11:28:02 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H
# include "../libft/includes/libft.h"
# include "../includes/op.h"

typedef struct  s_op
{
    char    name[6];
    int     number;
    int     params[3];
    int     op_code;
    int     nb_cycles;
    char    description[36];
    int     modify_carry;
    int     direct_size;
}               t_op;

typedef struct	s_player
{
	int			player_id;
	char		file[50];
	header_t	header;
	char		*instructions;
	int			nb_lives;
}				t_player;

typedef struct	s_env 
{
	char		arena[MEM_SIZE];
	int			cycle_to_die;
	int			nb_players;
	t_player	champions[MAX_PLAYERS];
	t_op		instructions[16];
}				t_env;

/*
** vm_initialization.c
*/

int				check_constants(void);
int				init_vm_champions(t_env *env);
int				init_vm_environment(t_env *env);

/*
** vm_options.c
*/


int				search_options(char *option);
int				check_options(char **argv, t_env *env);


/*
** vm_create_players.c
*/

int				ft_create_player(char *file, t_env *env);

/*
** vm_check_players.c
*/

int				check_magic(char *magic, t_env *env);
int				check_prog_size(char *prog_size, t_env *env);

/*
** vm_load_players.c
*/

/*
** vm_display_arena.c
*/

int				display_memory_area(char byte);
int				display_arena(t_env *env);

/*
** vm_display_errors.c
*/

void			display_usage(char **argv);
void			display_errors_with_value(int value, int code, t_env *env);
void			display_errors(char *error_message);

/*
** vm_debug.c
*/

int				check_initialization(t_env *env);
int				debug(t_env *env);

#endif
