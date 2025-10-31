/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:20:02 by kkaman            #+#    #+#             */
/*   Updated: 2025/10/31 18:20:45 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct	s_string
{
	int	minus;
	int	zero;
	int	plus;
	int	space;
	int	hash;
	int	width;
	int	precision;
	int	has_prec;
	char	specifier;
}	t_string;

void	ft_putchar(char c);
int		ft_printf(char const *input, ...);
int		print_handle(const char **s, va_list input);
void	handle_flag(const char **str);
void	handle_width(const char **str, t_string s);
void	handle_precision(const char **str, t_string *s);
void	init_s(t_string *s);


#endif
