#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"

#include <stdio.h>
#include "ft_printf.h"

int main()
{
	/*
	printf("|%1.-7d|\n", 123);
	printf("|%-10.7d|\n", 123);
	printf("|%8.-7d|\n", 123);

	printf("|%8.07d|\n", 123);
	printf("|%010.2d|\n", 123);
	*/

	/*---
	printf("|%-07.1c|\n", 'a');
	printf("|%07.3c|\n\n", 'a');
	ft_printf("|%-07.1c|\n", 'a');
	ft_printf("|%07.3c|\n", 'a');
	---*/
//	printf("||%s||\n", "abc");
//	ft_printf("%\n", "abc");
//	ft_printf("|%s|\n", "abc");
//	ft_printf("|%d|\n", "abc");
//	ft_printf("|%i|\n", "abc");
//	ft_printf("|%u|\n", "abc");
//	ft_printf("|%x|\n", "abc");
//	ft_printf("|%X|\n", "abc");
//	ft_printf("|%%|\n", "abc");
//	printf("----\n");
//	printf("||%c||\n", 'a');
	//ft_printf("|%c|\n", 'a');
//	ft_printf("|%10.5d|\n", 1234);
//	ft_printf("|%10.5d|\n", -1234);
	unsigned int x = 4294967161;
//	printf("-->|%-4.x|<--\n", x);//	==>	-->|ffffff79|<--
//	printf("-->|%-4.*x|<--\n", -4, x);//	==>	-->|ffffff79|<--
//	printf("-->|%-4.*x|<--\n", -3, x);	//==>	-->|ffffff79|<--
//	printf("-->|%-4.*x|<--\n", -2, x);	//==>	-->|ffffff79|<--
//	printf("-->|%-4.*x|<--\n", -1, x);//	==>	-->|ffffff79|<--
//	printf("-->|%-4.*x|<--\n", 0, x);//	==>	-->|ffffff79|<--

	ft_printf("-->|%-4.x|<--\n", x);//	==>	-->|ffffff79|<--
//	ft_printf("-->|%-4.*x|<--\n", -4, x);//	==>	-->|ffffff79|<--
//	ft_printf("-->|%-4.*x|<--\n", -3, x);	//==>	-->|ffffff79|<--
//	ft_printf("-->|%-4.*x|<--\n", -2, x);	//==>	-->|ffffff79|<--
//	ft_printf("-->|%-4.*x|<--\n", -1, x);//	==>	-->|ffffff79|<--
//	ft_printf("-->|%-4.*x|<--\n", 0, x);//	==>	-->|ffffff79|<--
	
	//ft_printf("%s\n", "abc");
	//ft_printf("%c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e');
//	printf("|세번째%d|\n\n", ft_printf("3"));
//	printf("|네번째%d|\n\n", ft_printf("4"));
//	printf("|다섯번쨰%d|\n\n", ft_printf("5"));
//	printf("|여섯번째%d|\n\n", ft_printf("6"));

	return (0);
}

#pragma GCC diagnostic pop
