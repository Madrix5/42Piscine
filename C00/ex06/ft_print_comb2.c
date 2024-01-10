/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:45:19 by adrijime          #+#    #+#             */
/*   Updated: 2023/12/14 15:27:13 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(char n1, char n2, char n3, char n4)
{
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, &" ", 1);
	write(1, &n3, 1);
	write(1, &n4, 1);
	if (n1 != '9' || n2 != '8' || n3 != '9' || n4 != '9')
		write(1, &", ", 2);
}

void	transform(int a, int b)
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;

	n1 = (a / 10) + 48;
	n2 = (a % 10) + 48;
	n3 = (b / 10) + 48;
	n4 = (b % 10) + 48;
	printer(n1, n2, n3, n4);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			transform(a, b);
			b++;
		}
		a++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
