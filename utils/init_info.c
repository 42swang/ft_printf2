#include "../ft_printf.h"

void	init_info(t_info *info)
{
	info->flag = 0;
	info->prec = -1;
	info->width = 0;
	info->ret_len = 0;
	info->prt_len = 0;
	info->type = 0;
}
