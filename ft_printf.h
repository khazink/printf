/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:20:02 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/14 10:42:36 by kkaman           ###   ########.fr       */
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
void	parse_specifier(const char **format, t_format *fmt);
void	parse_precision(const char **format, t_format *fmt);
void	parse_width(const char **format, t_format *fmt);
void	parse_flags(const char **format, t_format *fmt);
int		handle_conversion(t_format *fmt, va_list args);

int		print_char(t_format *fmt, int c);
int		print_string(t_format *fmt, char *str);
int		print_int(t_format *fmt, int n);
int		print_unsigned(t_format *fmt, unsigned int n);
int		print_hex(t_format *fmt, unsigned int n, int uppercase);
int		print_pointer(t_format *fmt, void *ptr);
int		print_percent(t_format *fmt);

char	get_sign(t_format *fmt, long num);
void	calc_int_lens(t_format *fmt, long num, char sign, t_lens *lens);
int		print_int_left(long num, char sign, t_lens *lens);
int		print_int_zero(long num, char sign, t_lens *lens);
int		print_int_right(long num, char sign, t_lens *lens);
int		get_num_len(long n);
int		print_num(long n);

void	calc_unsigned_lens(t_format *fmt, unsigned int n, t_lens *lens);
int		print_unsigned_left(unsigned int n, t_lens *lens);
int		print_unsigned_zero(unsigned int n, t_lens *lens);
int		print_unsigned_right(unsigned int n, t_lens *lens);

int		get_hex_len(unsigned long n);
void	calc_hex_lens(t_format *fmt, unsigned int n, t_lens *lens);
int		print_hex_left(t_format *fmt, unsigned int n, int up, t_lens *lens);
int		print_hex_zero(t_format *fmt, unsigned int n, int up, t_lens *lens);
int		print_hex_right(t_format *fmt, unsigned int n, int up, t_lens *lens);
int		print_hex_recursive(unsigned long n, int uppercase);

int		print_null_pointer(t_format *fmt);
void	calc_ptr_lens(unsigned long addr, t_format *fmt, t_lens *lens);
int		print_ptr_left(unsigned long addr, t_lens *lens);
int		print_ptr_right(unsigned long addr, t_lens *lens);

int		calc_string_lens(t_format *fmt, char *str, t_lens *lens);
int		print_string_left(char *str, t_lens *lens);
int		print_string_right(char *str, t_lens *lens);
int		ft_strlen(const char *s);

void	*ft_memset(void *b, int c, size_t len);
int		ft_isdigit(int c);
int		write_padding(char c, int count);
int		write_sign_and_zeros(char sign, int zeros);
int		handle_zero_prec_zero_val(t_format *fmt, unsigned long n);
#endif
