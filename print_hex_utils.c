/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:45:00 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/15 15:02:47 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calc_hex_lens(t_format *fmt, unsigned int n, t_lens *lens)
{
	lens->num_len = get_hex_len(n);
	lens->zeros = 0;
	if (fmt->has_prec && fmt->precision > lens->num_len)
		lens->zeros = fmt->precision - lens->num_len;
	lens->prefix_len = 0;
	if (fmt->hash && n != 0)
		lens->prefix_len = 2;
	lens->total_len = lens->num_len + lens->zeros + lens->prefix_len;
	lens->spaces = 0;
	if (fmt->width > lens->total_len)
		lens->spaces = fmt->width - lens->total_len;
}

int	print_hex_left(t_format *fmt, unsigned int n, int up, t_lens *lens)
{
	int	count;

	count = 0;
	if (fmt->hash && n != 0)
	{
		if (up)
			count += write(1, "0X", 2);
		else
			count += write (1, "0X", 2);
	}
	count += write_padding('0', lens->zeros);
	count += print_hex_recursive(n, up);
	count += write_padding(' ', lens->spaces);
	return (count);
}

int	print_hex_zero(t_format *fmt, unsigned int n, int up, t_lens *lens)
{
	int	count;

	count = 0;
	if (fmt->hash && n != 0)
	{
		if (up)
			count += write(1, "0X", 2);
		else
			count += write(1, "0x", 2);
	}
	count += write_padding('0', lens->spaces);
	count += print_hex_recursive(n, up);
	return (count);
}

int	print_hex_right(t_format *fmt, unsigned int n, int up, t_lens *lens)
{
	int	count;

	count = 0;
	count += write_padding(' ', lens->spaces);
	if (fmt->hash && n != 0)
	{
		if (up)
			count += write(1, "0X", 2);
		else
			count += write(1, "0x", 2);
	}
	count += write_padding('0', lens->zeros);
	count += print_hex_recursive(n, up);
	return (count);
}
