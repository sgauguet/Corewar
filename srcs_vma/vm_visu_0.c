/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_visu_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:48:14 by aserguie          #+#    #+#             */
/*   Updated: 2018/08/18 14:54:52 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	display_memory_area_ncurses(int i, char byte, int col, t_env *env)
{
	attron(COLOR_PAIR(col));
	if (env->arena2[i] >= UNDER_LINE && env->arena2[i] <= STAND_OUT)
		attron(A_UNDERLINE);
	if (env->arena2[i] >= STAND_OUT)
		attron(A_STANDOUT);
	if (byte == '\0')
		printw("00 ");
	else
		printw("%02x ", (unsigned char)byte);
	if ((i + 1) % 64 == 0)
		move(((i + 1) / 64) % 64 + 1, 0);
	attroff(COLOR_PAIR(col));
	attroff(A_STANDOUT);
	attroff(A_UNDERLINE);
	return (1);
}

void		display_info_ncurses(t_env *env, t_process *process)
{
	int reg;

	reg = 0;
	move (1 + reg, 200);
	printw("PROCESS ID = %d", process->id);
	while (reg < REG_NUMBER)
	{
		move(2 + reg, 200);
		printw("REG [ %02x ] = ", reg + 1);
		attron(COLOR_PAIR(process->col_pair));
		move(2 + reg, 213);
		if (process->reg[reg] == 0)
			printw("00000000");
		else
			printw("%08x", (unsigned int)process->reg[reg]);
		attroff(COLOR_PAIR(process->col_pair));
		reg++;
	}
	mvprintw(3 + reg, 200, "OPERATION = %02x", process->opcode);
	mvprintw(4 + reg, 200, "CARRY = %d", process->carry);
	mvprintw(5 + reg, 200, "PROCESS CURRENT = %04x",
		check_adress(process->current));
	mvprintw(6 + reg, 200, "CYCLES/SEC = %05d", env->cycle_sec);
	move(1, 0);
}

int		init_arena(t_env *env)
{
	int i;
	int j;
	int player;

	move(0, 0);
	printw("Press any key to START the game.");
	move(1,0);
	i = 0;
	j = 0;
	player = 1;
	while (i < MEM_SIZE && j < MEM_SIZE)
	{
		if (i == j)
			attron(A_STANDOUT);
		while (i < j + env->champions[player - 1].size)
		{
			display_memory_area_ncurses(i, env->arena[i], env->champions[player - 1].player_id, env);
			i++;
		}
		player++;
		j += MEM_SIZE / env->nb_players;
		if (player == 4 && j == MEM_SIZE - 1)
			j++;
		while (i < j)
		{
			display_memory_area_ncurses(i, env->arena[i], 0, env);
			i++;
		}
	}
	getch();
	return (1);
}

void	 ft_init_visu(t_env *env)
{
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	env->cycle_sec = 10000;
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		destroy_all(env, 1);
		exit(1);
	}
	env->option.visu = 1;
	keypad(stdscr, 1);
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
}

int		display_ncurses(t_env *env, t_process *process, int start, int pc)
{
	int	line;
	int col;

	line = start / 64;
	col = 3 * (start % 64);
	move(line + 1, col);
	start = check_adress(start);
	if (pc == 5)
		display_memory_area_ncurses(start, env->arena[start], 5, env);
	else
		display_memory_area_ncurses(start, env->arena[start], pc == 0 ? 
		env->arena2[start] % COLOR : process->col_pair % COLOR, env);
	if (pc != 0 && env->process.followed == process)
		display_info_ncurses(env, process);
	return (1);
}
