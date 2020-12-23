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
	int	i;
	int	j;

	if (sp == 'p')
	{
		i = 0;
		j = ft_strlen(str);
		while (str[i] && (str[i] == ' '))
			i++;
		if (i > 1)
		{
			str[i - 2] = '0';
			str[i - 1] = 'x';
		}
		else if (i == 1)
		{
			str[0] = 'x';
			str = ft_insertstr(str, "0");
		}
		else if (i == 0)
			str = ft_insertstr(str, "0x");
		if ((str[j] == ' ') && (str[j + 1] == ' '))
			str[j] = '\0';
	}
	return (str);
}

void	*ft_flag_space(char *str, char sp)
{
	int		i;
	char	*str2;

	i = 0;
	if (ft_elementof(sp, "dif"))
	{
		if (!ft_elementof('-', str))
		{
			str2 = ft_c_to_str(' ', NULL, NULL);
			str2 = ft_strjoin(str2, str);
			if (str2[ft_strlen(str2) - 1] == ' ')
				str2[ft_strlen(str2) - 1] = '\0';
			free(str);
			str = str2;
		}
	}
	return (str);
}
