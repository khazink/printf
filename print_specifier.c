/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:08:17 by kkaman            #+#    #+#             */
/*   Updated: 2025/10/31 18:09:08 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_specifier(t_string *s, va_list input)
{
	if (s->specifier == 'c')
		return (print_char(s, va_arg(input, int)));
	else if (s->specifier == 's')
		return (print_string(s, va_arg(input, char *)));
	else if (s->specifier == 'p')
		return (print_pointer(s, va_arg(input, void *)));
	else if (s->specifier == 'd' || s->specifier == 'i')
		return (print_int(s, va_arg(input, int)));
	else if (s->specifier == 'u')
		return (print_unsigned(s, va_arg(input, unsigned int)));
	else if (s->specifier == 'x')
		return (print_hex(s, va_arg(input, unsigned int), 0));
	else if (s->specifier == 'X')
		return (print_hex(s, va_arg(input, unsigned int), 1));
	else if (s->specifier == '%')
		return (print_percent(s));
	return (0);
}
