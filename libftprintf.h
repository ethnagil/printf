/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:09:20 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/23 18:00:45 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FLAGS "-0 *"
# define L_MODIFIER "lh"
# define MAXCONV 25
# define SPECIFIER "cspdiuxX"
# define TEN "0123456789"
# define HEX "0123456789ABCDEF"
# define HEXLOW "0123456789abcdef"

typedef void *(*t_flag_function)(char *, char);

int		ft_printf(
		const char *format, ...) __attribute__((__format__(__printf__,1,2)));
int		ft_readconvert(char *convert, const char *format, int i, va_list args);
char	*ft_va_argtostr(char spec, char *convert, va_list args, int *cnull);
char	*ft_apply_convert(char *prstr, char *convert, char spec);
int		ft_check_convert(char *convert, char spec);
void	ft_build_convert(t_flag_function *convert_fts, char *convert,
			int *specifier1, int *specifier2);

void	*ft_run_length(char *str, int specifier1, int specifier2, char spec);
void	*ft_flag_neg(char *str, char sp);
void	*ft_flag_space(char *str, char sp);
void	*ft_flag_zero(char *str, char sp);
void	*ft_flag_hash(char *str, char sp);

int		ft_elementof(char c, char *elements);
char	*ft_itoa_base(long long int n, char *base);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_c_to_str(char c, int *cnull, char *convert);
char	*ft_insertstr(char *str, char *strins);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

#endif
