/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:45:08 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/22 16:57:18 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_c_to_str(char c, int *cnull, char *convert)
{
	char str[2];

	if (c == 0)
	{
		if (ft_elementof('-', convert))
			*cnull = -1;
		else
			*cnull = 1;
	}
	str[0] = c;
	str[1] = '\0';
	return (ft_strdup(str));
}
