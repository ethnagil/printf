/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:25:06 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/18 19:34:35 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_add_leading(char *str, int n)
{
	char *str2;

	str2 = ft_c_to_str(' ');
	while (n-- > 1)
		str2 = ft_strjoin(str2, " ");
	str2 = ft_strjoin(str2, str);
	free(str);
	return (str2);

}

void	*ft_run_length(char *str, int specifier1, int specifier2, char spec)
{
	int		i;
	char	*str2;

	if (specifier2 > 0)
	{
		i = ft_strlen(str);
		if (ft_elementof(spec, "diouxX"))
		{
			if (ft_elementof('-', str))
					specifier2++;
			str = ft_add_leading(str, specifier2 - i);
			str = ft_flag_zero(str, spec);
		}
		else if (spec == 's')
			str[specifier2] = '\0';
	}
	if (specifier1 > 0)
	{
		i = ft_strlen(str);
		if (i < specifier1)
			str = ft_add_leading(str, specifier1 - i);
	}
	return (str);
}

void	*ft_flag_neg(char *str, char sp)
{
	int	i;
	int	j;
	int k;
	char *str2;
	
	(void)sp;
	str2 = ft_strdup(str);
	j = 0;
	k = 0;
	i = ft_strlen(str);
	while (str[j++] == ' ');
	while ((j + k) <= i)
	{
		str2[k] = str[(k - 1) + j];
		k++;
	}
	while (k < i)
		str2[k++] = ' ';
	str2[i] = 0;
	free(str);
	str = str2;
	return (str);
}

void	*ft_flag_space(char *str, char sp)
{
	int i;
	char *str2;

	i = 0;
	if (ft_elementof(sp, "dif"))
    {
		if (!ft_elementof('-', str))
		{
			str2 = ft_c_to_str(' '); 
			str2 = ft_strjoin(str2, str);
			if (str2[ft_strlen(str2)-1] == ' ')
				str2[ft_strlen(str2)-1] = '\0';
			free(str);
			str = str2;
		}
	}
	return (str);
}

void	*ft_flag_zero(char *str, char sp)
{
	int i;

	(void)sp;
	i = 0;
	while (str[i] && (str[i] == ' '))
	{
		str[i++] = '0';
	}
	if (str[i] == '-')
	{
		str[0] = '-';
		str[i] = '0';
	}

	return (str);
}

void	*ft_flag_hash(char *str, char sp)
{
	(void)sp;
	str = ft_strjoin(str, "-hash");
	return (str);
}
