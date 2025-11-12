/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:49:07 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/12 22:56:34 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_percent_right(int spaces)
{
	int	count;

	count = 0;
	count += write_padding(' ', spaces);
	count += write(1, "%", 1);
	return (count);
}

static int	print_percent_left(int spaces)
{
	int	count;

	count = 0;
	count += write(1, "%", 1);
	count += write_padding(' ', spaces);
	return (count);
}

int	print_percent(t_format *fmt)
{
	int	spaces;

	spaces = 0;
	if (fmt->width > 1)
		spaces = fmt->width - 1;
	if (fmt->minus)
		return (print_percent_left(spaces));
	return (print_percent_right(spaces));
}
