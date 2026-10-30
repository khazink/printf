/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:19:19 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/14 10:40:49 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// variadic function- can have variable number of argument. 3 things important in variadic function
// 1 .must have at least 1 argument. for us is format
// 2. ellipsis(...) is needed after the first arguments
// 3. program dont know where or how many memory is the variable is. so need to make sure it correct.
// incorrect data size will be undefined behaviour
int	ft_printf(char const *format, ...)
{
	int		count;
	va_list	args; //

	if (!format) // guard against no format
		return (-1); // return please check with subject
	count = 0;
	va_start(args, format); //this for start of va. will make args as 
	while (*format != '\0') // while the string is not terminator continue
	{
		if (*format == '%') //found % will go to parse format
		{
			format++; // will goes pass % and find the next char after %
			count += parse_format(&format, args); // check which format that it should use. it make it memory know how much to read 
		}
		else// if not continue to write the letter
		{
			count += write(1, format, 1);//write again
			format++;//moving format forwat
		}
	}
	va_end(args); //end va after complete all format
	return (count);//return the number of character that it 
}
