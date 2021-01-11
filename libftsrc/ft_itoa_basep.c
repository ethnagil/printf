/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:36:17 by egillesp          #+#    #+#             */
/*   Updated: 2021/01/04 17:33:21 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_intlenp(unsigned long long int n2, int basenum)
{
	int	i;

	if (n2 < 0)
	{
		i = 1;
		n2 = n2 * -1;
	}
	else
		i = 0;
	while ((n2) > 0)
	{
		n2 = n2 / basenum;
		i++;
	}
	return (i);
}

char	*ft_itoa_basep(unsigned long long int n, char *base)
{
	char		*str;
	int			len;

	len = ft_intlenp(n, ft_strlen(base));
	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = base[0];
		str[1] = '\0';
	}
	while (n > 0)
	{
		str[len - 1] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		len--;
	}
	return (str);
}
