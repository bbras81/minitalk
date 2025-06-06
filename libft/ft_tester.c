/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:49:30 by brunmigu          #+#    #+#             */
/*   Updated: 2025/05/05 12:07:24 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int				printf_ret;
	int				original_ret;
	int				ret_ft;
	int				ret_std;
	char			*str;
	char			empty_str[] = "";
	char			c;
	int				neg;
	int				zero;
	int				max_int;
	int				min_int;
	unsigned int	un;
	unsigned int	max_unsigned;
	void			*ptr;
	void			*null_ptr;

	original_ret = printf(" %x ->", -100);
	printf("este e o retorno do printf %d\n", original_ret);
	printf_ret = ft_printf(" %x ->", -100);
	printf("este e o retorno do ft_printf %d\n", printf_ret);
	/*-----------------------------------------------------------*/
	/*-----------------------------------------------------------*/
	str = "Hello, World!";
	c = 'A';
	 	int		num = 42;
	neg = -42;
	zero = 0;
	un = 3000000000;
	max_unsigned = 4294967295;
	max_int = 2147483647;
	min_int = -2147483648;
	ptr = (void *)0x7ffe2b8ef1dc;
	null_ptr = NULL;
	unsigned int	vals[] = {0, 1, 42, 300, 4294967295U};
	int	i = 0;
	printf("==== STRING TESTS ====\n");
	ret_ft = ft_printf("ft_printf: [%s]\n", str);
	ret_std = printf("printf   : [%s]\n", str);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	printf("==== EMPTY STRING TESTS ====\n");
	ret_ft = ft_printf("ft_printf: [%s]\n", empty_str);
	ret_std = printf("printf   : [%s]\n", empty_str);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	printf("==== CHARACTER TEST ====\n");
	ret_ft = ft_printf("ft_printf: [%c]\n", c);
	ret_std = printf("printf   : [%c]\n", c);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	printf("==== INTEGER TESTS ====\n");
	ret_ft = ft_printf("ft_printf: [INT_MIN: %i]\n", min_int);
	ret_std = printf("printf   : [INT_MIN: %i]\n", min_int);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("ft_printf: [INT_MAX: %d]\n", max_int);
	ret_std = printf("printf   : [INT_MAX: %d]\n", max_int);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("ft_printf: [Zero: %d]\n", zero);
	ret_std = printf("printf   : [Zero: %d]\n", zero);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("ft_printf: [Negative: %i]\n", neg);
	ret_std = printf("printf   : [Negative: %i]\n", neg);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	printf("==== UNSIGNED TESTS ====\n");
	ret_ft = ft_printf("ft_printf: [Unsigned: %u]\n", un);
	ret_std = printf("printf   : [Unsigned: %u]\n", un);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("ft_printf: [UINT_MAX: %u]\n", max_unsigned);
	ret_std = printf("printf   : [UINT_MAX: %u]\n", max_unsigned);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	printf("==== HEXADECIMAL TESTS ====\n");
	ret_ft = ft_printf("ft_printf: [Hex lower: %x]\n", 255);
	ret_std = printf("printf   : [Hex lower: %x]\n", 255);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("ft_printf: [Hex upper: %X]\n", 255);
	ret_std = printf("printf   : [Hex upper: %X]\n", 255);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("ft_printf: [ULONG_MAX: %X]\n", ULONG_MAX);
	ret_std = printf("printf   : [ULONG_MAX: %X]\n", ULONG_MAX);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	printf("==== POINTER TESTS ====\n");
	ret_ft = ft_printf("ft_printf: [Pointer: %p]\n", ptr);
	ret_std = printf("printf   : [Pointer: %p]\n", ptr);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("ft_printf: [NULL pointer: %p]\n", null_ptr);
	ret_std = printf("printf   : [NULL pointer: %p]\n", null_ptr);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	printf("==== NULL STRING TEST ====\n");
	ret_ft = ft_printf("ft_printf: [NULL string: %s]\n", NULL);
	ret_std = printf("printf   : [NULL string: %s]\n", NULL);
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	printf("==== PERCENT SIGN TEST ====\n");
	ret_ft = ft_printf("ft_printf: [%%]\n");
	ret_std = printf("printf   : [%%]\n");
	printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	printf("==== TEST WITH %%u ====\n");
	while (i < 5)
	{
	 		printf("Testing with value: %u\n", vals[i]);
	 		ret_ft = ft_printf("ft_printf: [%u]\n", vals[i]);
	 		ret_std = printf("printf   : [%u]\n", vals[i]);
			printf("Return ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);
	 		i++;
 	}
	/*-----------------------------------------------------------*/
	/*-----------------------------------------------------------*/
	/*-----------------------------------------------------------*/
}
