/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:00:00 by adrijime          #+#    #+#             */
/*   Updated: 2023/11/28 14:27:31 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*
int	main(void)
{
	int	*a;
	int	*b;
	int	resd;
	int	resm;

	resd = 10;
	resm = 3;
	a = &resd;
	b = &resm;
	printf("resuldiv = %d resulmod = %d", resd, resm);
	ft_ultimate_div_mod(a, b);
	printf("resuldiv = %d resulmod = %d", resd, resm);
	return (0);
}
*/
