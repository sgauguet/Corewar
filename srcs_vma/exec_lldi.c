
#include "corewar.h"

int	check_lldi(t_env *env, t_process *process, t_param *param)
{
	if ((process->ocp[0] != 1 && process->ocp[0] != 2 && process->ocp[0] != 3)
		|| (process->ocp[1] != 1 && process->ocp[1] != 2)
		|| process->ocp[2] != 1)
		return (0);
	if (!params_size_ocp(env, process, param))
		return (0);
	param->value[2] = (int)env->arena[check_adress(process->current + 2
			+ param->size[0] + param->size[1])];
	if (param->value[2] < 1 || param->value[2] > REG_NUMBER)
		return (0);
	return (1);
}

int	exec_lldi(t_env *env, t_process *process)
{
	t_param	param;
	char	tmp[2];
	char	tmp2[2];
	char	to_store[8];

	if (!check_lldi(env, process, &param))
		return (0);
	copy_memory_area(env, tmp, check_adress(process->current + 2), param.size[0]);
	param.value[0] = (param.size[0] == 2) ? (tmp[0] << 8 | (unsigned char)tmp[1]) : tmp[0];
	copy_memory_area(env, tmp2, check_adress(process->current + 2 + param.size[0]), param.size[1]);
	param.value[1] = (param.size[1] == 2) ? (tmp2[0] << 8 | (unsigned char)tmp2[1]) : tmp2[0];
	param.adress = check_adress((param.value[0] + param.value[1]));
	copy_memory_area(env, to_store, param.adress, 8);
	process->reg[param.value[2]] = ft_atoi_base(to_store);
	process->carry = 1;
	show_operations(env, process, &param);
	return (1);
}

