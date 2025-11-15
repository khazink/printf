/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:36:45 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/15 15:04:22 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(long n)
{
	int		count;
	char	c;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += print_num(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	print_hex_recursive(unsigned long n, int uppercase)
{
	int		count;
	char	*base;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += print_hex_recursive(n / 16, uppercase);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	write_padding(char c, int count)
{
	int	written;

	written = 0;
	while (count > 0)
	{
		written += write(1, &c, 1);
		count--;
	}
	return (written);
}

int	write_sign_and_zeros(char sign, int zeros)
{
	int	count;

	count = 0;
	if (sign)
		count += write(1, &sign, 1);
	count += write_padding('0', zeros);
	return (count);
}

int	handle_zero_prec_zero_val(t_format *fmt, unsigned long n)
{
	if (fmt->has_prec && fmt->precision == 0 && n == 0)
		return (write_padding(' ', fmt->width));
	return (-1);
}
