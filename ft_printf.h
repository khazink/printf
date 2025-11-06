/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:20:02 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/06 16:12:18 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		hash;
	int		width;
	int		precision;
	int		has_prec;
	char	specifier;
}	t_format;

typedef	struct s_lens
{
	int	num_len;
	int	zeros;
	int	spaces;
	int	prefix_len;
	int	total_len;
	int	print_len;
}	t_lens;

int		ft_printf(const char *input, ...);

int		parse_format(const char **format, va_list args);
void	init_format(t_format *fmt);
int		handle_conversion(t_format *fmt, va_list args);
void	parse_specifier(const char **format, t_format *fmt);
void	parse_precision(const char **format, t_format *fmt);
void	parse_width(const char **format, t_format *fmt);
void	parse_flags(const char **format, t_format *fmt);

int		print_char(t_format *fmt, int c);
int		print_string(t_format *fmt, char *str);
int		print_int(t_format *fmt, int n);
int		print_unsigned(t_format *fmt, unsigned int n);
int		print_hex(t_format *fmt unsigned int n, int uppercae);
int		print_pointer(t_format *fmt, void *ptr);
int		print_percent(t_format *fmt);

int		calc_string_lens(t_format *fmt, char *str, t_lens *lens);
int		print_string_left(char *str, t_lens *lens);
int		print_string_right(char *str, t_lens *lens);

int		ft_strlen(const char *s);
int		*ft_memset(void *b, int c, size_t len);
int		ft_isdigit(int c);
int		write_padding(char c, int count);
int		write_sign_and zeros(char sign, int zeros);
void	ft_putchar(char c);

int		get_num_len(long n);
int		get_hex_len(unsigned long n);
int		print_num(long n);
int		print_hex_recursive(unsigned long n, int uppercase);



void	parse_flag(const char **format, t_format *fmt);
void	handle_width(const char **str, t_string s);
void	handle_precision(const char **str, t_string *s);
void	init_s(t_string *s);
int		print_specifier(t_string *s, va_list input);
int		print_char(t_string *s, int c);
int		print_string(t_string *s, char *str);
void    ft_putchar(char c);
int		write_padding(int padding);
#endif
