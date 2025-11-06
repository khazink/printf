/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 01:22:45 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/06 16:26:29 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calc_string_lens(t_format *fmt, char *str, t_lens *lens)
{
	int	len;

	len = ft_strlen(str);
	lens->print_len = len;
	if (fmt->has_prec && fmt->precision < len)
		lens->print_len = fmt->precision;
	lens->space = 0;
	if (fmt->width > lens->print_len)
		lens->spaces = fmt->width - lens->print_len;
	return (lens->print_len);
}

int	print_string_left(char *str, t_lens *lens)
{
	int	count;

	count = 0;
	count += write(1, str, lens->print_len);
	count += write_padding(' ', lens->spaces);
	return (count);
}

int	print_string_right(char *str, t_lens *lens)
{
	int	count;

	count = 0;
	count += write_padding(' ', lens->spaces);
	count += write(1, str, lens->print_len);
	return (count);
}

int	print_string(t_format *fmt, char *str)
{
	t_lens	lens;

	if (!str)
		str = "(null)";
	calc_string_lens(fmt, str, &lens);
	if (fmt->minus)
		return (print_string_left(str, &lens));
	return (print_string_right(str, &lens));
}
