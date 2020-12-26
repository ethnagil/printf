/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:36:17 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/16 18:40:07 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_intlen(long int n2, int basenum)
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

char	*ft_itoa_base(long long int n, char *base)
{
	char		*str;
	long long	basenum;
	int			len;
//	int			i;

//	basenum = ft_strlen(base);
	len = ft_intlen(n, ft_strlen(base));
	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = base[0];
		str[1] = '\0';
	}
	while(n > 0)
	{
	//	i = n % basenum;
		str[len - 1] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		len--;
	}
	return (str);
}
