/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_conv_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:00:21 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/23 17:55:59 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_readconvert(char *convert, const char *format, int f, va_list args)
{
	int		j;
	int		k;
	char	*wildcard;

	ft_bzero(convert, MAXCONV);
	j = 0;
	while ((ft_elementof((char)format[f], FLAGS)) ||
		(ft_isdigit(format[f]) || (format[f] == '.')) ||
		(ft_elementof((char)format[f], L_MODIFIER)))
	{
		if (format[f] == '*')
		{
			k = 0;
			wildcard = ft_itoa_base((long long)va_arg(args, int), TEN);
			while (wildcard[k])
				convert[j++] = wildcard[k++];
			j--;
			free(wildcard);
		}
		else
			convert[j] = format[f];
		j++;
		f++;
	}
	return (f);
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
	if (ft_check_convert(convert, spec))
	{
		ft_build_convert(convert_fts, convert, &specifier1, &specifier2);
		prstr = ft_run_length(prstr, specifier1, specifier2, spec);
		while (convert_fts[i])
		{
			prstr = convert_fts[i++](prstr, spec);
		}
	}
	if (spec == 'p')
		prstr = ft_flag_hash(prstr, spec);
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
					(ft_elementof('.', convert))))
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
		*specifier2 *= neg;
		if (*specifier2 == 0)
			*specifier2 = 'n';
	}
}

void	ft_build_convert(t_flag_function *convert_fts, char *convert,
		int *specifier1, int *specifier2)
{
	int i;
	int neg;

	i = 0;
	neg = 1;
	*specifier1 = 0;
	*specifier2 = 0;
	while ((ft_elementof((char)convert[i], FLAGS)))
	{
		if (convert[i] == '-')
			convert_fts[i] = &ft_flag_neg;
		if (convert[i] == ' ')
			convert_fts[i] = &ft_flag_space;
		if (convert[i] == '0')
			convert_fts[i] = &ft_flag_zero;
		i++;
	}
	convert_fts[i] = NULL;
	ft_build_convert_num(convert, i, specifier1, specifier2);
}
