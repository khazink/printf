/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 02:14:42 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/14 10:31:26 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(t_format *fmt, int n)
{
	long	num;
	char	sign;
	t_lens	lens;
	int		result;

	num = (long)n;
	if (num < 0)
		result = handle_zero_prec_zero_val(fmt, (unsigned long)(-num));
	else
		result = handle_zero_prec_zero_val(fmt, (unsigned long)num);
	if (result >= 0)
		return (result);
	sign = get_sign(fmt, num);
	calc_int_lens(fmt, num, sign, &lens);
	if (fmt->minus)
		return (print_int_left(num, sign, &lens));
	if (fmt->zero && !fmt->has_prec)
		return (print_int_zero(num, sign, &lens));
	return (print_int_right(num, sign, &lens));
}
