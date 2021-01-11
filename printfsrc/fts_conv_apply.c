/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_conv_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:00:21 by egillesp          #+#    #+#             */
/*   Updated: 2021/01/07 14:34:06 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_add_prefix(char *prstr, char *convert, char spec)
{
	(void)convert;
	if ((spec == 'p') || (ft_elementof('#', convert) && ((spec == 'x') ||
		(spec == 'X'))))
		prstr = ft_flag_hash(prstr, spec);
	if (ft_elementof('+', convert))
		prstr = ft_flag_plus(prstr, spec);
	if (ft_elementof(' ', convert))
		prstr = ft_flag_plus(prstr, spec);
	return (prstr);
}

char	*ft_apply_convert(char *prstr, char *convert, char spec)
{
	t_flag_function	*convert_fts;
	int				specifier1;
	int				specifier2;
	int				i;

	convert_fts = malloc(sizeof(t_flag_function) * (ft_strlen(convert) + 1));
	if (!convert_fts)
		return (0);
	i = 0;
	prstr = ft_add_prefix(prstr, convert, spec);
	if (ft_check_convert(convert, spec))
	{
		ft_build_convert(convert_fts, convert, &specifier1, &specifier2);
		if ((specifier2 == 'n') && (prstr[0] == '+') && (prstr[1] == '0') &&
			(ft_strlen(prstr) == 2))
			prstr[1] = 0;
		prstr = ft_run_length(prstr, specifier1, specifier2, spec);
		while (convert_fts[i])
		{
			prstr = convert_fts[i++](prstr, spec);
		}
	}
	free(convert_fts);
	return (prstr);
}

int		ft_check_convert(char *convert, char spec)
{
	int i;

	(void)spec;
	i = 0;
	while (convert[i])
	{
		if ((convert[i] == '0') && ((ft_elementof('-', convert)) ||
			((ft_elementof('.', convert) && !ft_elementof(spec, "sc")))))
		{
			while (convert[i])
			{
				convert[i] = convert[(i) + 1];
				i++;
			}
		}
		if ((convert[i] == '.') || (!convert[i]) || ((convert[i] != '0') &&
					ft_isdigit(convert[i])))
			break ;
		i++;
	}
	return (1);
}

void	ft_build_convert_num(char *convert, int i, int *specifier1,
							int *specifier2)
{
	int neg;

	neg = 1;
	while (ft_isdigit(convert[i]))
		*specifier1 = ((*specifier1 * 10) + (convert[i++] - 48));
	if (convert[i++] == '.')
	{
		if (convert[i] == '-')
		{
			neg = -1;
			i++;
		}
		else if (!ft_isdigit(convert[i]))
			*specifier2 = 'n';
		while (ft_isdigit(convert[i]))
			*specifier2 = ((*specifier2 * 10) + (convert[i++] - 48));
		if (neg == -1)
		{
			*specifier1 = *specifier2;
			*specifier2 = 0;
		}
		if (*specifier2 == 0)
			*specifier2 = 'n';
	}
}

void	ft_build_convert(t_flag_function *convert_fts, char *convert,
		int *specifier1, int *specifier2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	*specifier1 = 0;
	*specifier2 = 0;
	if (ft_elementof('-', convert))
		convert_fts[i++] = &ft_flag_neg;
	while ((ft_elementof((char)convert[j], FLAGS)))
	{
		if (convert[j] == '0')
			convert_fts[i++] = &ft_flag_zero;
		j++;
	}
	if (ft_elementof(' ', convert))
		convert_fts[i++] = &ft_flag_space;
	convert_fts[i] = NULL;
	ft_build_convert_num(convert, j, specifier1, specifier2);
}
