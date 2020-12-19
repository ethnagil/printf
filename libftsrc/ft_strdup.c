/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:40:10 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/19 19:25:00 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_strdup(char *src)
{
	char	*src2;
	int		strlen;
//	size_t	i;

	if (!src)
		return (src);
	strlen = ft_strlen(src);
	if ((src2 = (char *)malloc(sizeof(char) * (strlen + 1))) == 0)
		return (NULL);
	ft_strlcpy(src2, src, strlen + 1);
	return (src2);
}
