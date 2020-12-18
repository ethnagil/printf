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

char	*ft_itoa_base(long long int n, char *base, int neg)
{
	char		*str;
	long long	i;

	i = ft_strlen(base);
	if (n < 0)
	{
		neg = 1;
		n = n * -1;
	}
	if (!(str = (char *)malloc(sizeof(char) * (2 + neg))))
		return (NULL);
	if (n >= i)
		str = ft_strjoin(ft_itoa_base(n / i, base, neg),
				ft_itoa_base(n % i, base, 0));
	else if (n < i)
	{
		if (neg == 1)
			str[0] = '-';
		str[0 + neg] = base[n];
		str[1 + neg] = '\0';
	}
	return (str);
}
