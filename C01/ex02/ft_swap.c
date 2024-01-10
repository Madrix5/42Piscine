/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:52:10 by adrijime          #+#    #+#             */
/*   Updated: 2023/11/29 14:35:25 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int	*a, int	*b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
int	main(void)
{
	int	num1;
	int	num2;
	int	*a;
	int	*b;

	num1 = 3;
	num2 = 2;
	a = &num1;
	b = &num2;
	printf("num1 = %d num2 = %d\n", num1, num2);
	ft_swap(a, b);
	printf("num1 = %d num2 = %d", num1, num2);
	return (0);
}
*/
