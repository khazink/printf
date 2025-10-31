/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:58:36 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/01 00:53:21 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_flag(const char **str)
{
	while (**str)
	{
		if (**str == '-')
			s->minus = 1;
		else if (**str == '0')
			s->zero = 1;
		else if (**str == '+')
			s->plus = 1;
		else if (**str == ' ')
			s->space = 1;
		else if (**str == '#')
			s->hash = 1;
		else
			break ;
		(*str)++;
	}
}

void	handle_width(const char **str, t_string s)
{
	s->width = 0;
	while (ft_isdigit(**format))
	{
		s->width = s->width * 10 + (**str - '0');
		(*str)++;
	}
}

void	handle_precision(const char **str, t_string s)
{
	s->precision = 0;
	s->precision = 0;
	if (**str == '.')
	{
		s->has_prec = 1;
		(*str)++;
		while (ft_isdigit(**str))
		{
			s->precision = s->precision * 10 + (**str - '0');
			(*str)++;
		}
	}
}

void	init_format(t_format *s)
{
	ft_memset(s, 0, sizeof(t_fomat));
}
