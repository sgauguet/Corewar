/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:53:01 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/28 11:21:19 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H
# include "../libft/includes/libft.h"
# include "../includes/op.h"

// REG_SIZE modifiable ??

typedef struct  s_op
{
    char    name[6];
    int     params_number;
    int     params[3];
    char	op_code;
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
	char		instructions[CHAMP_MAX_SIZE];
	int			nb_lives;
}				t_player;

typedef struct	s_process
{
	int					reg[REG_NUMBER];
	int					current;
	int					pc;
	char				opcode;
	int					cycle_before_exec;
	int					alive;
	struct s_process	*next;
}				t_process;

typedef struct	s_stack
{
	t_process	*first_process;
	int			nb_process;
}				t_stack;

typedef struct	s_env 
{
	char		arena[MEM_SIZE];
	int			cycle;
	int			cycle_to_die;
	int			nb_players;
	t_player	champions[MAX_PLAYERS];
	t_op		instructions[16];
	t_stack		process;
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

int				load_players(t_env *env);

/*
** vm_exec_process.c
*/

int				exec_process(t_env *env);
int				run_the_game(t_env *env);

/*
** vm_destroy_process.c
*/

int				destroy_process(t_env *env, t_process *process);
int				search_dead_process(t_env *env);

/*
** vm_process_stack.c
*/

int				new_instruction(t_env *env, t_process *process);
int				create_process(t_env *env, int *reg, int start_position);
int				init_process_stack(t_env *env);

/*
** vm_instructions.c
*/

int				exec_instruction(t_env *env, t_process *process);
int				instruction_size(t_env *env, t_process *process);
int				search_instruction(t_env *env, char opcode);

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

int				display_process(t_env *env);
int				display_champions(t_env *env);
int				display_instructions(t_env *env);
int				debug(t_env *env);

#endif
