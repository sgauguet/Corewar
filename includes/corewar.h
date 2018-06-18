/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:53:01 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/18 10:50:05 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H
# include "../libft/includes/libft.h"
# include "../includes/op.h"

typedef struct	s_player
{
	int			player_id;
	header_t	header_s;
	char		*instructions;
	int			nb_lives;
}				t_player;

typedef struct	s_env 
{
	char		arena[MEM_SIZE];
	int			cycle_to_die;
	int			nb_players;
	t_player	*champions;
}				t_env;

/*
** vm_initialization.c
*/

int				init_vm_environment(char **argv, t_env *env);


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


/*
** vm_load_players.c
*/

/*
** vm_display_errors.c
*/

void			display_usage(char **argv);
void			display_errors(char *error_message);

#endif
