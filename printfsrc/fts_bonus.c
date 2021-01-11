/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:24:19 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/23 16:48:44 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	*ft_flag_hash(char *str, char sp)
{
	if ((str[0] == '0') && (ft_strlen(str) == 1) && (sp != 'p'))
		return (str);
	if ((sp == 'p') || (sp == 'x'))
		str = ft_insertstr(str, "0x");
	if (sp == 'X')
		str = ft_insertstr(str, "0X");
	return (str);
}

void	*ft_flag_plus(char *str, char sp)
{
	if (((sp == 'd') || (sp == 'i')) && !ft_elementof('-', str))
		str = ft_insertstr(str, "+");
	return (str);
}

void	*ft_flag_space(char *str, char sp)
{
	int	i;

	if ((sp == 'i') || (sp == 'd'))
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '+')
			{
				str[i] = ' ';
				return (str);
			}
			i++;
		}
	}
	return (str);
}
