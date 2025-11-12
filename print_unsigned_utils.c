/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:31:14 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/07 10:43:43 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calc_unsigned_lens(t_format *fmt, unsigned int n, t_lens *lens)
{
	lens->num_len = get_num_len(n);
	lens->zeros = 0;
	if (fmt->has_prec && fmt->precision > lens->num_len)
		lens->zeros = fmt->precision - lens->num_len;
	lens->total_len = lens->num_len + lens->zeros;
	lens->spaces = 0;
	if (fmt->width > lens->total_len)
		lens->spaces = fmt->width - lens->total_lens;
}

int	print_unsigned_left(unsigned int n, t_lens *lens)
{
	int	count;

	count = 0;
	count += write_padding('0', lens->zeros);
	count += print_num(n);
	count += write_padding(' ', lens->spaces);
	return (count);
}

int	print_unsigned_zero(unsigned int n, t_lens *lens)
{
	int	count;

	count = 0;
	count += write_padding('0', lens->spaces);
	count += print_num(n);
	return (count);
}

int	print_unsigned_right(unsigned int n, t_lens *lens)
{
	int	count;

	count = 0;
	count += write_padding(' ', lens->spaces);
	count += write_padding('0', lens->zeros);
	count += print_num(n);
	return (count);
}
