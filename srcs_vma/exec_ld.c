
#include "corewar.h"

int		exec_ld(t_env *env, t_process *process)
{
	char	tmp[4];
	t_param param;

	if ((process->ocp[0] != 1 && process->ocp[0] != 3) || process->ocp[1] != 1)
		return (0);
	if (!params_size_ocp(env, process, &param))
		return (0);
	copy_memory_area(env, tmp, check_adress(process->current + 1), param.size[0]);
	param.value[0] = (param.size[0] == 2) ? (tmp[0] << 8 | (unsigned char)tmp[1]) : (tmp[0] << 24 | (unsigned char)tmp[1] << 16 | (unsigned char)tmp[2] << 8 | (unsigned char)tmp[3]);
//	param.adress = check_adress(param.size[0] % IDX_MOD + process->current);
	param.value[1] = (int)env->arena[check_adress(param.size[0]  + process->current + 2)];
	if (param.value[1] >= REG_NUMBER || param.value[1] <= 0)
		return (0);
	process->reg[param.value[1] - 1] = param.size[0] == 2  ? indirect_value(env, param.value[0] % IDX_MOD) : param.value[0];
	process->carry = 1;
	show_operations(env, process, &param);
	return (1);
}
