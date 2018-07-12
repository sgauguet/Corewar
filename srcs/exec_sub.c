#include "corewar.h"

int	exec_sub(t_env *env, t_process *process)
{
	int		register1;
	int		register2;
	int		register3;

	register1 = (int)env->arena[check_adress(process->current + 2)];
	register2 = (int)env->arena[check_adress(process->current + 3)];
	register3 = (int)env->arena[check_adress(process->current + 4)];
	if (process->ocp[0] != 1 || process->ocp[1] != 1 || process->ocp[2] != 1)
		return (0);
	if ((register1 < 0 || register1 > REG_NUMBER) || (register2 < 1 ||
	register2 > REG_NUMBER) || (register3 < 1 || register3 > REG_NUMBER))
		return (0);
	process->reg[register3] = process->reg[register1] -
		process->reg[register2];
	if (process->reg[register3] == 0)
		process->carry = 1;
	else
		process->carry = 0;
	return (1);
}
