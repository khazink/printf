/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:16:51 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/12 22:32:13 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_null_pointer(t_format *fmt)
{
	int		count;
	int		spaces;
	char	*null_str;
	int		len;

	count = 0;
	null_str = "(nil)";
	len = 5;
	spaces = 0;
	if (fmt->width > len)
		spaces = fmt->width - len;
	if (fmt->minus)
	{
		count += write(1, null_str, len);
		count += write_padding(' ', spaces);
	}
	else
	{
		count += write_padding(' ', spaces);
		count += write(1, null_str, len);
	}
	return (count);
}

int	print_pointer(t_format *fmt, void *ptr)
{
	unsigned long		addr;
	t_lens				lens;

	if (!ptr)
		return (print_null_pointer(fmt));
	addr = (unsigned long)ptr;
	calc_ptr_lens(addr, fmt, &lens);
	if (fmt->minus)
		return (print_ptr_left(addr, &lens));
	return (print_ptr_right(addr, &lens));
}
