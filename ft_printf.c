/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:19:19 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/01 00:55:42 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	input;

	if (!str)
		return (-1);
	count = 0;
	va_start(input, str);
	while (*str != '\0')
	{
		if (*str == '%')
			count += print_handle(&str, input);
		else
		{
			ft_putchar(*input);
			count++;
		}
		str++;
	}
	va_end(input);
	return (count);
}

int	print_handle(const char **str, va_list input)
{
	t_string	s;

	(*str)++;
	init_s(&s);
	handle_flag(str, &s);
	handle_width(str, &s);
	handle_precision(str, &s);
	s->spefifier = **str;
	(*str)++;
	return (print_specifier(&s, input));
}
