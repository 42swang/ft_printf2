#include "../ft_printf.h"

void	handle_info(t_info *info)
{
	if (info->prec < 0)
	{
		info->flag &= ~DOT;
		info->prec = -1;
	}
	if (info->width < 0)
	{
		info->flag |= MINUS;
		info->width *= -1;
	}
	if (info->type == 'd' || info->type == 'i' || info->type == 'u')
	{
		if (info->flag & ZERO && info->flag & DOT && !(info->flag & MINUS))
			info->flag &= ~ZERO;
	}
}