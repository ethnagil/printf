/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:14:31 by egillesp          #+#    #+#             */
/*   Updated: 2021/01/06 17:54:13 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define TEST(...) assert(printf("   printf: " __VA_ARGS__) == ft_printf("ft_printf: " __VA_ARGS__)); 

int main(void)
{
	const char *format = "salut %---------------------------------------------------------------0000000--------------------------------------------------------------------------------------------0000000--------------------------------------------------------------------------------------------0000000--------------------------------------------------------------------------------------------0000000--------------------------------------------------------------------------------------------0000000--------------------------------------------------------------------------------------------0000000--------------------------------------------------------------------------------------------0000000--------------------------------------------------------------------------------------------0000000-------------------------------------------------------------------------------------------0000000------------------------------d\n";
	printf(format, 15);
	ft_printf(format, 15);
	//
	setbuf(stdout, NULL);
/*
	printf("|%0*.*i|\n", 2, -2, 8);
	ft_printf("|%0*.*i|\n", 2, -2, 8);

	printf("|%+.i|\n", 0);
	ft_printf("|%+.i|\n", 0);

		printf("|%+-03.d|\n", 0);
	ft_printf("|%+-03.d|\n", 0);

		printf("|%+-03.2d|\n", 1);
	ft_printf("|%+-03.2d|\n", 1);

	printf("p|%#-03.2x |\n", 0);
	ft_printf("f|%#-03.2x |\n", 0);
	*/
	TEST("p%#x\n", 1)
	TEST("p |%+d| \n", 0)
	TEST("p |%d| \n", 0)
	TEST("|%0*.*i|\n", 2, -2, 8)
	TEST("|%+.i|\n", 0)
	TEST("|%+-03.d|\n", 0)
	TEST("|%+-03.2d|\n", 1)
	TEST("p|%#-03.2x |\n", 0)
	TEST("p%#x\n", 1)
	TEST("p |%+d| \n", 0)
	TEST("p |%d| \n", 0)
	TEST(" %+d \n", 0)
	TEST(" %+2d \n", 0)
	TEST(" %+02d \n", 0)
	TEST(" %+-03d \n", 0)
	TEST(" %+-03.d \n", 0)

	TEST("|%0*.*d|\n", 8, -2, 8)
	TEST("|%08.-2d|\n", 8)
	TEST("|%-08.2d|\n", 8)

	TEST("|%*.*d|\n", 8, -2, 8)
	TEST("|%8.-2d|\n", 8)
	TEST("|%-8.2d|\n", 8)

	TEST("%.*d\n", -2, 8)
	TEST("%.-2d\n", 8)
/*
	printf("p%02.-5i\n", 888);
	ft_printf("f%02.-5i\n", 888);

	printf("p%010.-3c\n", 'a');
	ft_printf("f%010.-3c\n", 'a');

	printf("p%015.-10s\n", "888");
	ft_printf("f%015.-10s\n", "888");
*/
	TEST("p%02.-5i\n", 888)
	TEST("p%010.-3c\n", 'a')
	TEST("p%015.-10s\n", "888")
	TEST("Salut\n")
	TEST("Ceci est un nombre %d %d %d %d %d\n", 42, -42, 0, INT_MAX, INT_MIN)
	TEST("Ceci est %s\n", NULL)
	TEST("Ceci est %.3s\n", NULL)
	TEST("test: '%c'\n", 0)

	TEST("Salut %10s\n", "salut")
	TEST("Salut %5s\n", "salut")
	TEST("Salut %3s\n", "salut")

	TEST("Salut %-10s\n", "salut")
	TEST("Salut %-5s\n", "salut")
	TEST("Salut %-3s\n", "salut")

	TEST("Salut %010s\n", "salut")
	TEST("Salut %05s\n", "salut")
	TEST("Salut %03s\n", "salut")

	TEST("Salut %-010s\n", "salut")
	TEST("Salut %-05s\n", "salut")
	TEST("Salut %-03s\n", "salut")

	TEST("Salut %*s\n", 10, "salut")
	TEST("Salut %*s\n", 5, "salut")
	TEST("Salut %*s\n", 3, "salut")

	TEST("test %*s\n", -10, "salut")
	TEST("Salut %-*s\n", 10, "salut")
	TEST("Salut %-*s\n", 5, "salut")
	TEST("Salut %-*s\n", 3, "salut")

	TEST("Salut %0*s\n", 10, "salut")
	TEST("Salut %0*s\n", 5, "salut")
	TEST("Salut %0*s\n", 3, "salut")

	printf("--------------\n");

	TEST("Salut %.*s\n", 10, "salut")
	TEST("Salut %.*s\n", 5, "salut")
	TEST("Salut %.*s\n", 3, "salut")

	TEST("Salut %-.*s\n", 10, "salut")
	TEST("Salut %-.*s\n", 5, "salut")
	TEST("Salut %-.*s\n", 3, "salut")

	TEST("Salut %0.*s\n", 10, "salut")
	TEST("Salut %0.*s\n", 5, "salut")
	TEST("Salut %0.*s\n", 3, "salut")

	printf("--------------\n");

	TEST("Salut %*.*s\n", 3, 10, "salut")
	TEST("Salut %*.*s\n", 5, 1, "salut")
	TEST("Salut %*.*s\n", 3, 1, "salut")

	TEST("Salut %-*.*s\n", 10, 10, "salut")
	TEST("Salut %-*.*s\n", 5, 5, "salut")
	TEST("Salut %-*.*s\n", 3, 2, "salut")

	TEST("Salut %0*.*s\n", 10, 5, "salut")
	TEST("Salut %0*.*s\n", 5, 3, "salut")
	TEST("Salut %0*.*s\n", 3, 7, "salut")

	printf("--------------\n");
	TEST("Salut %010s\n", "salut")
	TEST("Salut %0*s\n", 10, "salut")
	TEST("Salut %0*.5s\n", 10, "salut")
	TEST("Salut %010.5s\n", "salut")
	TEST("Salut %010.5d\n", 42)
	*/
}