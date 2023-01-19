/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:43:51 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/26 14:33:54 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define SPECIFIERS	"cspdiuxX%"

typedef struct s_format
{
	int	hash;
	int	space;
	int	plus;
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	precision;
	int	type;
}		t_format;

// If ft_printf (by using ft_format) detects a '%' in str, we determine
// which flags, widths and conversion types have been specified and print
// the argument accordingly.
// If there is no %, we simply print the character.

int			ft_printf(const char *str, ...);
int			ft_format(char *str, va_list *args);

// The function ft_format_specifications test for flags, width, precision
// and then determines the conversion type. All this will be stored in the
// new structure 'format'.

int			ft_format_specifications(char *str, va_list *args);
t_format	ft_format_default(void);
t_format	ft_format_flags(char *str, t_format format);
t_format	ft_format_width(char *str, t_format format);

// Determines the conversion type and refers it to the respective print 
// function.

int			ft_print_type(t_format format, va_list *args);

// Helper functions that adjust the output accordingly when width is
// specified and which are used for most conversion types. Handles the '-'
// and '0' flags.

void		ft_width_adjustment(t_format format, char *str);
void		ft_minus_adjustment(t_format format, char *str);
void		ft_zero_adjustment(t_format format, char *str);
void		ft_default_adjustment(t_format format, char *str);

// Print functions for conversion type '%' and 'c'. These types accept the
// '-' and '0' flags as well as width specifications.

int			ft_print_c_pct(t_format format, va_list *args);
void		ft_format_c_pct(t_format format, int c);

// Print functions for conversion type 's'. This type considers the '-'
// flag and width and precision specifications.

int			ft_print_s(t_format format, char *s);
int			ft_format_s(t_format format, char *s_str);

// Print functions for the conversion types 'd' and 'i'. These types consider
// the '+', ' ', '-', & '0' flags as well as width and precision specifications.

int			ft_print_d_i(t_format format, int n);
char		*ft_str_d_i(t_format format, int n);
char		*ft_sign_d_i(t_format format, int n);
char		*ft_precision_d_i(t_format format, char *d_i_str, int n, int x);
char		*ft_precision_d_i_2(t_format format, char *d_i_str, int n, int x);
char		*ft_precision_zero_d_i(t_format format, \
char *d_i_str, int n, int x);
void		ft_width_d_i(t_format format, char *d_i_str, int n);

// Print functions for the conversion type 'u'. This type considers the
// '-' & '0' flags and width and precision specifications.

int			ft_print_u(t_format format, unsigned int u);
char		*ft_str_u(t_format format, unsigned int u);
char		*ft_itoa_u(unsigned int u);
int			ft_digitcount_u(unsigned int u);
char		*ft_precision_u(t_format format, char *u_str, unsigned int u);
char		*ft_precision_u_2(t_format format, char *u_str);

// Print function for the conversion types 'x' & 'X'. These types consider
// the '-', '0', & '#' flags as well as width and precision specifications.

int			ft_print_x(t_format format, unsigned int x);
char		*ft_str_x(t_format format, unsigned int x);
char		*ft_str_x_2(t_format format, unsigned int x);
char		*ft_itoa_x(unsigned int x, char *hex_base);
int			ft_digitcount_x(unsigned int x);
char		*ft__precision_x(t_format format, char *x_str, unsigned int x);
char		*ft_precision_x_2(t_format format, char *x_str, unsigned int x);
char		*ft_precision_zero_x(t_format format, char *x_str, int i);
void		ft_width_x(t_format format, char *x_str, unsigned int x);

// Print functions for the conversion type 'p'. This type considers the 
// '-' & '0' flags as well as width specifications.

int			ft_print_p(t_format format, size_t p);
char		*ft_str_p(size_t p);
char		*ft_itoa_p(size_t p);
int			ft_digitcount_p(size_t p);

#endif
