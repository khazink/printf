/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:19:19 by kkaman            #+#    #+#             */
/*   Updated: 2025/10/29 17:07:37 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *input, ...)
{
	int count;
	va_list	args;

	count = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			count += print_handle(*input);
		}
		else
		{
			ft_putchar(*input);
			count++;
		}
		input++;
	}
	return (count);
}

int	print_handle(const char **input)
{
	(*input)++; //skip %
	
	//check for flags
	while (**input == '-' || **input == '0' || **input == '.'
	     || **input == '#' || **input == ' ' || **input == '+')
	{
		handle_flag(**input);
		(*input)++;
	}
	
	//check for width
	while (ft_isdigit(**input))
	{
		handle_width(**input);
		(*input)++;
	}

	//check for precision
	while (**input == '.')
	{
		handle_precision(**input)
	}

	//check for specifier
	return (len)
}
