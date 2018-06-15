/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:53:01 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/14 16:42:35 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H
# include "../libft/includes/libft.h"
# include "../includes/op.h"

typedef struct	s_env 
{
	char arena[MEM_SIZE];
	int cycle_to_die;
	int	nb_players;
	char	*champions[3];
}				t_env;

int	ft_create_player(char *file, t_env *env);

#endif
