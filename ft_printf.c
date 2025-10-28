#include "ft_printf.h"
#include "stdio.h"

int	ft_printf(char const *input, ...)
{
	int count;

	count = 0;
	while (*input != '\0')
	{
		if (*input != '%')
		{
			ft_putchar(*input);
			count++;
		}
		input++;
	}
	return (count);
}

int	main(void)
{
	int	count;

	count = ft_printf("All are great");
	printf("\n%d\n",count);
	count = ft_printf("get some %d here");
	printf("\n2nd row %d\n", count);	
	return 0;
}	
