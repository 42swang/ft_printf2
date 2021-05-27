#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define MINUS 1
# define ZERO 2
# define DOT 4
# define WIDTH 8
# define TYPE "cspdiuxX%"


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_info
{
	unsigned char	flag;
	int				prec;
	int				width;
	int				ret_len;
	int				prt_len;
	char			type;
}	t_info;

/*----sources----*/
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_putstr(char *str);
int		ft_isdigit(int c);
char	*ft_itoa(long long int n);
int		ft_putchar(int c);

/*-----utils----*/
void	just_print(const char *format, int *i, t_info *info);
void	init_info(t_info *info);
void	padding_left(t_info *info);
void	padding_right(t_info *info);
int		type_char(int c, t_info *info);
int		type_str(char *s, t_info *info);
void	care_prec(t_info *info, char *str);


/*---ft_printf---*/
int		ft_printf(const char *format, ...);

#endif
