/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:46:06 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/18 19:34:27 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int		main()
{
	int p;
	int c = 'a';
	char *s = "abc";
	int i = -123;
	int d = -123;
	unsigned int x = 14;
	unsigned int X = 14;

	p = 9;
	/*
//Tests with no specifiers
	printf("hello, world!");
	ft_printf("hello, world!");
	printf("");
	ft_printf("");
	printf("\t\n\r\v\f\n");
	ft_printf("\t\n\r\v\f\n");
//Nospec tests with successive calls
	printf("hello");  printf("world");
	ft_printf("hello"); ft_printf("world");
	printf("he"); printf(" is alive");
	ft_printf("he"); ft_printf(" is alive");
	printf("is alive"); printf(" he");
	ft_printf("is alive"); ft_printf(" he");
//%% Tests

	printf("\n");
	printf("%%");
	printf("%5%");
	printf("%-5%\n");
	printf("%05%\n");
	printf("yo%-05%\n");
	ft_printf("\n");
	ft_printf("%%");
	ft_printf("%5%");
	ft_printf("%-5%\n");
	ft_printf("%05%\n");
	ft_printf("my%-05%\n");

//Null specifier tests
printf("%");
printf("%5");
printf("%05");
printf("%-05");
printf("%-5");

ft_printf("%");
ft_printf("%5");
ft_printf("%05");
ft_printf("%-05");
ft_printf("%-5");

printf("this %s is %s\n", "", "hello");
ft_printf("this %s is %s\n", "", "hello");
printf("%16s", "nark nark\n");
ft_printf("%16s", "nark nark\n");

printf("%-16s\n", "nark nark");
printf("%.3s%.2s\n", "holla", "bitch");
printf("1-%3.7s%7.7s\n", "hello", "world");
printf("%7.3s%7.3s\n", "hello", "world");
printf("%-7s%5s\n", "hello", "world");
*/
printf("1-%32s\n", NULL);
printf("1-%.3s\n", "NULL");
/*
ft_printf("%-16s\n", "nark nark");
ft_printf("%.3s%.2s\n", "holla", "bitch");
ft_printf("2-%3.7s%7.7s\n", "hello", "world");
ft_printf("%7.3s%7.3s\n", "hello", "world");
*/
ft_printf("%-7s%5s\n", "hello", "world");

ft_printf("2-%32s\n", NULL);  /*printf wrirtes (null) ??? */
ft_printf("2-%.3s\n", "NULL");
/*
printf("%*s\n", 32, "abc");
printf("%-*s\n", 32, "abc");
printf("%*i\n", 14, 94827);
printf("y%.*i\n", 6, -3);
ft_printf("%*s\n", 32, "abc");
ft_printf("%-*s\n", 32, "abc");
ft_printf("%*i\n", 14, 94827);
ft_printf("m%.*i\n", 6, -3);


	printf("--------------printf\n");
	printf("1-hello%-03c\n", 'a');

	printf("2-%-03c\n", 'a');
	
	printf("3-%-03s\n", "a");

	printf("4-%-12.3s\n", "hello");
	printf("5-%-4.2s\n", "hello");
	printf("1hello%3c\n", 'a');

	printf("2%3c\n", 'a');
	
	printf("3%3s\n", "a");

	printf("4%12.3s\n", "hello");
	printf("5%4.2s\n", "hello");
	printf("6% -12.3d\n", 999999);
	printf("7% 12.3i\n", -999999);
	printf("8%20p\n", &p);
	printf("9%12.3u\n", 999999);
	printf("a%12.3x\n", 14);
	printf("b%012X\n", 14);
	printf("c%-20p\n", &p);
	printf("d%-12.3u\n", 999999);
	printf("e%-12.3x\n", 14);
	printf("f%0-12X\n", 14);

	printf("--------------ft_printf\n");
	ft_printf("hello%-03c\n", c);
	
	ft_printf("%-03c\n", c);
		
	ft_printf("%-03s\n", "a");
	
	ft_printf("%-12.3s\n", "hello");
	ft_printf("%-4.2s\n", "hello");

	ft_printf("% -12.3d\n", 999999);
	
	ft_printf("% 12.3i\n", -999999);
	
	ft_printf("%-12p\n", &p);
	ft_printf("%-12.3u\n", 999999);
	ft_printf("%-12.3x\n", 14);
	ft_printf("%0-12X\n", 14);


	ft_printf("hello%03c", c);
	
	ft_printf("%- 3c\n", c);
		
	ft_printf("%0-3s\n", "a");
	
	ft_printf("%- 12.3s\n", "hello");
	ft_printf("%-04.2s\n", "hello");

	ft_printf("% -12.3d\n", 999999);
	
	ft_printf("% 12.3i\n", -999999);
	
	ft_printf("%- 12p\n", &p);
	ft_printf("%- 12.3u\n", 999999);
	ft_printf("%- 12.3x\n", 14);
	ft_printf("%0- 12X\n", 14);	
*/
	return (0);
}
//typedef struct		s_format
//{
//	int	flag[6];  0 : 0 padding on left except if precision is given for diuxX
//				 - : left justify with blanks on right.. overrides 0
//				' ': leave a space before a + number (signed conversion d, i) */
//	int	width; /* minimum field width */
//	int dot; /* indicates the decimal places will be given in the next variable, 0 if empty 
//	int decimals; /* decimal places or string length */ 
//	int conversion; /* cspduxX */
//}					t_format;
//
/*
printf("%0- 12.3c", 'a');
undefined behaviour
   - precision .999 
   - 0
   - " "
printf("%- 012.3s", "hello");
undefined behaviour
   - precision .999 (truncate s to precision 2 chars) 
   - 0
   - " "

printf("% 0-12.3d", -999);
   - precision .999 ignored

printf("% 0-12.3i", -999);
   - precision .999 ignored

printf("%-0 12p\n", &p);
undefined behaviour
   - precision .999 
   - precision 99 ignored
   - 0
   - " "
printf("% -012.3u", 999);
undefined behaviour
   - " "

printf("%-0 12.3x", 14);
undefined behaviour
   - " "

printf("%-0 12.3X", 14);
undefined behaviour
   - " "

g 0 ignored when flag - is present
12.3 takes first 3 charachers and padds to 12
 continue with all cases*/ 
