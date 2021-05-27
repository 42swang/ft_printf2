#include "../ft_printf.h"

void	care_prec(t_info *info, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (info->flag & DOT && info->prec < len)
		info->prt_len = info->prec;
	else
		info->prt_len = len;
}
