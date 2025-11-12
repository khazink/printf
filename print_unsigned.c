/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:15:07 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/07 10:12:31 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(t_format *fmt, unsigned int n)
{
	t_lens	lens;
	int		result;

	result = handle_zero_prec_zero_val(fmt, (unsigned long)n);
	if (result >= 0)
		return (result);
	calc_unsigned_lens(fmt, n, &lens);
	if (fmt->minus)
		return (print_unsigned_left(n, &lens));
	if (fmt->zero && !fmt->has_prec)
		return (print_unsigned_zero(n, &lens));
	return (print_unsigned_right(n, &lens));
}
