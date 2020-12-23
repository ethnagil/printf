/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:23:53 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/22 17:24:09 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_insertstr(char *str, char *strins)
{
	char	*str2;
	int		i;
	int		j;

	i = ft_strlen(strins) + ft_strlen(str);
	if ((str2 = (char *)malloc(sizeof(char) * (i + 1))) != 0)
	{
		i = 0;
		while (strins[i])
		{
			str2[i] = strins[i];
			i++;
		}
		j = 0;
		while (str[j])
			str2[i++] = str[j++];
		str2[i] = '\0';
		if (str)
			free(str);
		return(str2);
	}
	return (0);
}
