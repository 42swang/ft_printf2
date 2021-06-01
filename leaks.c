#include "ft_printf.h"
//ft_printf.h 경로를 제대로 설정하시오

int main()
{
	ft_printf("%c %s %p %d %i %u %x %X %%", '1', "2", 3, -4, -5, 6, 7, 8);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
