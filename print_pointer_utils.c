/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:29:59 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/12 22:48:45 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	calc_ptr_lens(unsigned long addr, t_format *fmt, t_lens *lens)
{
	lens->num_len = get_hex_len(addr);
	lens->total_len = lens->num_len + 2;
	lens->spaces = 0;
	if (fmt->width > lens->total_len)
		lens->spaces = fmt->width - lens->total_len;
}

int	print_ptr_left(unsigned long addr, t_lens *lens)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += print_hex_recursive(addr, 0);
	count += write_padding(' ', lens->spaces);
	return (count);
}

int	print_ptr_right(unsigned long addr, t_lens *lens)
{
	int	count;

	count = 0;
	count += write_padding(' ', lens->spaces);
	count += write(1, "0x", 2);
	count += print_hex_recursive(addr, 0);
	return (count);
}
