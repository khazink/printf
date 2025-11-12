/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:26:22 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/07 10:30:17 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(t_format *fmt, unsigned int n, int uppercase)
{
	t_lens	lens;
	int		result;

	result = handle_zero_prec_zero_val(fmt, (unsigned long)n);
	if (result >= 0)
		return (result);
	calc_hex_lens(fmt, n, &lens);
	if (fmt->minus)
		return (print_hex_left(fmt, n, uppercase, &lens));
	if (fmt->zero && !fmt->has_prec)
		return (print_hex_zero(fmt, n, uppercase, &lens));
	return (print_hex_right(fmt, n, uppercase, &lens));
}
