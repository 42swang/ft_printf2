#include "../ft_printf.h"

void	padding_right(t_info *info)
{
	if (!(info->flag & MINUS))
		return ;
	while (info->width - info->prt_len > 0)
	{
		info->ret_len += ft_putchar(' ');
		info->width -= 1;
	}
	//오른쪽 패딩은 공백밖에 없음, 오른쪽패딩이라는건 왼쪽정렬인데 왼쪽정렬은 제로플래그가 없음
}
