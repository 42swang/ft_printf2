#include "../ft_printf.h"

int	print_zero(t_info *info)
{
	int		prec_padding;
	char	*nbr;

	prec_padding = 0;
	nbr = "";
	info->prt_len = 0;
	padding_left(info);
	padding_right(info);
	return(info->ret_len);
}