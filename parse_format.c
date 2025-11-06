/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:02:02 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/06 12:49:32 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format(t_format, *fmt)
{
	ft_memset(fmt, 0, sizeof(t_format));
}

int	handle_conversion(t_format *fmt, va_list args)
{
	if (fmt->specifier == 'c')
		return (print_char(fmt, va_arg(args, int)));
	if (fmt->specifier == 's')
		return (print_string(fmt, va_arg(args, *char)));
	if (fmt->specifier == 'p')
		return (print_pointer(fmt, va_arg(args, void *)));
	if (fmt->specifier == 'd' || fmt->specifier == 'i')
		return (print_int(fmt, va_arg(args, int)));
	if (fmt->specifier == 'u')
		return (print_unsigned(fmt, va_arg(args, unsigned int)));
	if (fmt->specifier == 'x')
		return (print_hex(fmt, va_arg(args, unsigned int), 0));
	if (fmt->specifier == 'X')
		return (print_hex(fmt, va_arg(args, unsigned int), 1));
	if (fmt->specifier == '%')
		return (print_percent(fmt));
	return (0);
}

int	parse_format(const char **format, va_list args)
{
	t_format	fmt;

	init_format(&fmt);
	parse_flags(format, &fmt);
	parse_width(format, &fmt);
	parse_precision(format, &fmt);
	parse_specifier(format, &fmt);
	return (handle_conversion(&fmt, args));
}
