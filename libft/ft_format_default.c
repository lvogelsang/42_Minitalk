/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_default.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:13:48 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/20 12:35:15 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Creation of a structure that can store all the specifications that
// need to be applied when printing.

// '#' => Specifies that the value should be printed in alternate form
// (for x and X conversions).

// ' ' => Specifies that a blank should be placed before a positive number
// in signed format. This flag is ignored if the '+' flag exists 
// (for d and i conversions).

// '+' => Specifies that there should always be a sign placed before a
// number in signed format (for d and i conversions).

// '-' => Specifies left adjustment of the output.

// '0' => Specifies that zero-padding should be used rather than 
// blank-padding. A '-' overrides a '0' if both are used.

t_format	ft_format_default(void)
{
	t_format	format;

	format.hash = 0;
	format.space = 0;
	format.plus = 0;
	format.minus = 0;
	format.zero = 0;
	format.width = 0;
	format.dot = 0;
	format.precision = 0;
	format.type = 0;
	return (format);
}
