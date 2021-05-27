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
	ft_printf("%\n", "abc");
	ft_printf("|%s|\n", "abc");
//	ft_printf("|%d|\n", "abc");
//	ft_printf("|%i|\n", "abc");
//	ft_printf("|%u|\n", "abc");
//	ft_printf("|%x|\n", "abc");
//	ft_printf("|%X|\n", "abc");
//	ft_printf("|%%|\n", "abc");
//	printf("----\n");
//	printf("||%c||\n", 'a');
	//ft_printf("|%c|\n", 'a');
	return (0);
}

#pragma GCC diagnostic pop
