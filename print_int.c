/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 02:14:42 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/06 16:48:03 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_int_zero_prec(t_format *fmt, long num)
{
	if (fmt->has_prec && fmt->precision == 0 && num == 0)
		return (write_padding(' ', fmt->width));
	return (-1);
}

int	print_int(t_format *fmt, int n)
{
	long	num;
	char	sign;
	t_lens	lens;
	int		result;

	num = (long)n;
	result = handle_int_zero_prec(fmt, num);
	if (result >= 0)
		return (result);
	sign = get_sign(fmt, num);
	calc_int_lens(fmt, num, sign, &lens);
	if (fmt->minus)
		return (print_int_left(num, sign, &lens));
	if (fmt->zero && !fmt->has_prec)
		return (print_int_zero(num, sign, &lens));
	return (print_int_right);
}
