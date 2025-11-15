/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:30:28 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/15 22:58:17 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char **format, t_format *fmt)
{
	while (**format)
	{
		if (**format == '-')
			fmt->minus = 1;
		else if (**format == '0')
			fmt->zero = 1;
		else if (**format == '+')
			fmt->plus = 1;
		else if (**format == ' ')
			fmt->space = 1;
		else if (**format == '#')
			fmt->hash = 1;
		else
			break ;
		(*format)++;
	}
}

void	parse_width(const char **format, t_format *fmt)
{
	fmt->width = 0;
	while (ft_isdigit(**format))
	{
		fmt->width = fmt->width * 10 + (**format - '0');
		(*format)++;
	}
}

void	parse_precision(const char **format, t_format *fmt)
{
	fmt->precision = 0;
	fmt->has_prec = 0;
	if (**format == '.')
	{
		fmt->has_prec = 1;
		(*format)++;
		while (ft_isdigit(**format))
		{
			fmt->precision = fmt->precision * 10 + (**format - '0');
			(*format)++;
		}
	}
}

void	parse_specifier(const char **format, t_format *fmt)
{
	fmt->specifier = **format;
	(*format)++;
}
