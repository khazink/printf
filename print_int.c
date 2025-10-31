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

	num = (long)n;
	sign = get_sign(s, num);
	if (s->has_prec && s->precision == 0 && num == 0)
	{
		lens[2] = s->width;
		while (len[2]--)
			write(1, " ", 1);
		return (s->width);
	}
	len[0] = get_num_len(num < 0 ? -num : num);
	len[1] = 0;
	if
}
