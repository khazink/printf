/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 02:14:42 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/01 02:30:09 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_int(t_string *s, int n)
{
	long	num;
	char	sign;
	int	lens[3];
	int	count;

	num = (long)n;
	sign = get_sign(s, num);
	if (s->has_prec && s->precision == 0 && num == 0)
	{
		count = s->width;
		while (s->width--)
			write(1, " ", 1);
		return (count);
	}
	calculate_lens(s, num, sign, lens)
	if (s->minus)
		return (print_with_left_justify(s, num, sign, lens));
	if (s->zero && !s->has_prec)
		return (print_with_zero_padding(s, num, sign, lens));
	return (print_with_space_padding(num, sign, lens);
}

static void calculate_lens(t_string *s, long num, char sign, int *lens)
{
	long	abs_num;

	abs_num = num;
	if (num < 0)
		abs_num = -num;
	lens[0] = get_num_len(abs_num);
	lens[1] = 0;
	if (s->has_prec && s->precision > lens[0])
		lens[1] = s->precision - lens[0];
	lens[2] = s->width - (lens[0] + lens[1]);
	if (sign)
		lens[2] -= 1;
	if (lens[2] < 0)
		lens[2] = 0;
}

static char	get_sign(s, num)
{
	if (num < 0)
		return ('-');
	else if (s->plus)
		return ('+');
	else if (s->space)
		return (' ');
	return (0);
}

static int	print_with_left_justify(t_string s, long num, char sign, int *lens)
{
	
}
