/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:58:36 by kkaman            #+#    #+#             */
/*   Updated: 2025/10/30 13:00:06 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_flag(const char **str)
{
	while (**str)
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

void	handle_width(const char **str, t_
