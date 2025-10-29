/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:18:57 by kkaman            #+#    #+#             */
/*   Updated: 2025/10/29 15:19:48 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int     main(void)
{
        int     count;

        count = ft_printf("All are great");
        printf("\n%d\n",count);
        count = ft_printf("get some %d here");
        printf("\n2nd row %d\n", count);
        return 0;
}

