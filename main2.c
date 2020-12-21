#include "libftprintf.h"
#include <stdio.h>

int	main()
{
/*
	printf("1-p0 % .3s\n", "cccc");
	ft_printf("2-f0 % .3s\n", "cccc");
	printf("1-pp %.50d\n", 10000);
	ft_printf("2-fp %.50d\n", 10000);

	printf("a1-%-5%\n");
	ft_printf("a2-%-5%\n");

	printf("b1-%-05%\n");
	ft_printf("b2-%-05%\n");
	
	printf("c1-%-32s\n", "abc");
	ft_printf("c2-%-32s\n", "abc");

   	printf("d1-%-16s\n", "nark nark");	
   	ft_printf("d2-%-16s\n", "nark nark");


	printf("1e-%-5%\n");
	ft_printf("2e-%-5%\n");
	

	printf("a1-%.s\n", "hello");
	ft_printf("a2-%.s\n", "hello");
	
	printf("b1-%.0s\n", "hello");
	ft_printf("b2-%.0s\n", "hello");


printf("a1-hello, %s.\n", NULL);
ft_printf("a2-hello, %s.\n", NULL);
printf("b1-%s\n", NULL);
ft_printf("b2-%s\n", NULL);
printf("c1-%32s\n", NULL);
ft_printf("c2-%32s\n", NULL);
printf("d1-%2s\n", NULL);
ft_printf("d2-%2s\n", NULL);
printf("e1-%-32s\n", NULL);
ft_printf("e2-%-32s\n", NULL);
printf("f1-%-16s\n", NULL);
ft_printf("f2-%-16s\n", NULL);
printf("g1-%-3s\n", NULL);
ft_printf("g2-%-3s\n", NULL);
printf("d?-%d\n", NULL);

printf("a1-%.03s\n", "hi low\0don't print me lol\0");
ft_printf("a2-%.03s\n", "hi low\0don't print me lol\0");
printf("b1-%.09s\n", "hi low\0don't print me lol\0");
ft_printf("b2-%.09s\n", "hi low\0don't print me lol\0");
printf("c1-%.03s\n", NULL);
ft_printf("c2-%.03s\n", NULL);
printf("d1-%.09s\n", NULL);
ft_printf("d2-%.09s\n", NULL);

	printf("a1-%-.00s\n", "hi low\0don't print me lol\0");
	ft_printf("a2-%-.00s\n", "hi low\0don't print me lol\0");

printf("1a-%.4i\n", 5263);
ft_printf("2a-%.4i\n", 5263);
printf("1b-%.4i\n", -2372);
ft_printf("2b-%.4i\n", -2372);
printf("1c-%.3i\n", 13862);
ft_printf("2c-%.3i\n", 13862);
printf("1d-%.3i\n",-23646);
ft_printf("2d-%.3i\n",-23646);

printf("a %08.5i\n", 34);
printf("b %010.5i\n", -216);
printf("c %08.5i\n", 0);
printf("d %08.3i\n", 8375);
printf("e %08.3i\n", -8473);
printf("f %08i\n", -8473);
ft_printf("a2%08.5i\n", 34);
ft_printf("b2%010.5i\n", -216);
ft_printf("c2%08.5i\n", 0);
ft_printf("d2%08.3i\n", 8375);
ft_printf("e2%08.3i\n", -8473);
ft_printf("f2%08i\n", -8473);

*/
static char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;
/*
printf("1 %p\n", NULL);
printf("2 %5p\n", NULL);

printf("3 %2p\n", NULL);

printf("4 %.p\n", NULL);

printf("5 %5.p\n", NULL);
printf("6 %2.p\n", NULL);
printf("7 %9.2p\n", 1234);
printf("8 %2.9p\n", 1234);
printf("9 %.5p\n", 0);
printf("x %.0p\n", 0);
printf("y %5p\n", 0);
ft_printf("12%p\n", NULL);
ft_printf("22%5p\n", NULL);

ft_printf("32%2p\n", NULL);

ft_printf("42%.p\n", NULL);

ft_printf("52%5.p\n", NULL);
ft_printf("62%2.p\n", NULL);
ft_printf("72%9.2p\n", 1234);
ft_printf("82%2.9p\n", 1234);
ft_printf("92%.5p\n", 0);
ft_printf("x2%.0p\n", 0);
ft_printf("y2%5p\n", 0);



printf("g %-70p\n",&a01);
printf("i %-16p\n",&a01);
printf("j %-8p\n",&a01);
printf("k %-32p\n",&a01);
ft_printf("g2%-70p\n",&a01);
ft_printf("i2%-16p\n",&a01);
ft_printf("j2%-8p\n",&a01);
ft_printf("k2%-32p\n",&a01);

printf("g %-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
printf("i %-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
printf("j %-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
printf("k %-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
ft_printf("g2%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
ft_printf("i2%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
ft_printf("j2%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
ft_printf("k2%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
*/
/*
printf("a %c\n", '\0');
printf("b %5c\n", '\0');
printf("c %-5c\n", '\0');

ft_printf("a1%c\n", '\0');
ft_printf("b1%5c\n", '\0');
ft_printf("c1%-5c\n", '\0');
*/
printf("d %c\n", -0);
printf("e %c\n", 0);

ft_printf("d1%c\n", -0);
ft_printf("e1%c\n", 0);

/*
printf("f %-*.*s\n", 7, 3, "yolo");
	
printf("g %.*s\n", -3, "hello");

printf("h %-*.*s\n", -7, -3, "yolo");
printf("i %.*i\n", -6, -3);

ft_printf("f1%-*.*s\n", 7, 3, "yolo");

ft_printf("g1%.*s\n", -3, "hello");

ft_printf("h1%-*.*s\n", -7, -3, "yolo");
ft_printf("i1%.*i\n", -6, -3);
*/

	return (0);

}
