#include "../ft_printf.h"

int	type_num(int num, t_info *info)
{
	int		prec_padding;
	int		nbr_len;
	char	*nbr;

	prec_padding = 0;
	nbr = ft_itoa(num);
	if (num == 0 && info->prec == 0)
		return (print_zero(info));
	nbr_len = ft_strlen(nbr);
	info->prt_len = ft_strlen(nbr);
	if (num < 0)
		info->prt_len += 1;
	if (info->flag & DOT)
		nbr_with_prec(info, nbr_len, &prec_padding);
	if (num < 0 && (info->flag & ZERO || info->flag & MINUS))
		info->ret_len += ft_putchar('-');
	padding_left(info);
	if (num < 0 && !(info->flag & MINUS) && !(info->flag & ZERO))
		info->ret_len += ft_putchar('-');
	while (prec_padding-- > 0)
		info->ret_len += ft_putchar('0');
	info->ret_len += ft_putstr(nbr);
	padding_right(info);
	return(info->ret_len);
}