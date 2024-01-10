/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:07:18 by adrijime          #+#    #+#             */
/*   Updated: 2023/11/29 14:33:00 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int main(void)
{
	int	a;
	int	b;
	int	division;
	int	modulo;
	int	*div;
	int	*mod;

	a = 10;
	b = 3;
	division = 0;
	modulo = 0;
	div = &division;
	mod = &modulo;
	printf("div = %d mod = %d", division, modulo);
	ft_div_mod(a, b, div, mod);
	printf("div = %d mod = %d", division, modulo);
	return (0);	
}
*/
