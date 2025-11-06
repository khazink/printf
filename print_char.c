/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:22:59 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/06 14:41:35 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char_left(int c, int padding)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	count += write_padding(' ', padding);
	return (count);
}

int	print_char_right(int c, int padding)
{
	int	count;

	count = 0;
	count += write_padding(' ', padding);
	count += write(1, &c, 1);
	return (count);
}

int	print_char(t_format *fmt, int c)
{
	int	padding;

	padding = 0;
	if (fmt->width > 1)
		padding = fmt->width - 1;
	if (fmt->minus)
		return (print_char_left(c, padding));
	return (print_char_right(c, padding));
}
