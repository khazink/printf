/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:19:32 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/14 10:31:56 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_sign(t_format *fmt, long num)
{
	if (num < 0)
		return ('-');
	if (fmt->plus)
		return ('+');
	if (fmt->space)
		return (' ');
	return (0);
}

void	calc_int_lens(t_format *fmt, long num, char sign, t_lens *lens)
{
	if (num < 0)
		lens->num_len = get_num_len(-num);
	else
		lens->num_len = get_num_len(num);
	lens->zeros = 0;
	if (fmt->has_prec && fmt->precision > lens->num_len)
		lens->zeros = fmt->precision - lens->num_len;
	lens->total_len = lens->num_len + lens->zeros;
	if (sign)
		lens->total_len += 1;
	lens->spaces = 0;
	if (fmt->width > lens->total_len)
		lens->spaces = fmt->width - lens->total_len;
}

int	print_int_left(long num, char sign, t_lens *lens)
{
	int	count;

	count = 0;
	count += write_sign_and_zeros(sign, lens->zeros);
	if (num < 0)
		count += print_num(-num);
	else
		count += print_num(num);
	count += write_padding(' ', lens->spaces);
	return (count);
}

int	print_int_zeros(long num, char sign, t_lens *lens)
{
	int	count;

	count = 0;
	if (sign)
		count += write(1, &sign, 1);
	count += write_padding('0', lens->spaces);
	if (num < 0)
		count += print_num(-num);
	else
		count += print_num(num);
	return (count);
}

int	print_int_right(long num, char sign, t_lens *lens)
{
	int	count;

	count = 0;
	count += write_padding(' ', lens->spaces);
	count += write_sign_and_zeros(sign, lens->zeros);
	if (num < 0)
		count += print_num(-num);
	else
		count += print_num(num);
	return (count);
}
