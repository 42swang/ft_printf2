#include "../ft_printf.h"

void	str_with_prec(t_info *info, int *str_len)
{	
	if (info->flag & DOT && info->prec < *str_len)
	{
		*str_len = info->prec;
		info->prt_len = info->prec;
	}
}

void	nbr_with_prec(t_info *info, int nbr_len, int *prec_padding)
{
	if (info->flag & DOT && info->prec > nbr_len)
	{
		*prec_padding = info->prec - nbr_len;
		info->prt_len += *prec_padding;
	}
}