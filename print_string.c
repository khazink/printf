/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 01:22:45 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/01 02:00:35 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	write_padding(int padding)
{
	int	count;

	count = 0;
	while (padding-- > 0)
		count += write(1, " ", 1);
	return (count);
}

int	print_string(t_string *s, char *str)
{
	int	count;
	int	padding;
	int	print_len;

	if (!str)
		str = "(null)";
	count = 0;
	print_len = ft_strlen(str);
	if (s->has_prec && s->precision < print_len)
		print_len = s->precision;
	if (s->width > print_len)
		padding = s->width - print_len;
	else
		padding = 0;
	if (s->minus)
	{
		count += write(1, str, print_len);
		count += write_padding(padding);
	}
	else
	{
		count += write_padding(padding);
		count += write(1, str, print_len);
	}
	return (count);
}
