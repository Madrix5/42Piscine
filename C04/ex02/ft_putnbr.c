/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:07:14 by adrijime          #+#    #+#             */
/*   Updated: 2023/12/11 17:08:45 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int nb)
{
	nb += '0';
	write(1, &nb, 1);
}

void	ft_putnbr(int nb)
{
	int	m;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb <= 9)
	{
		ft_putchar(nb);
	}
	else
	{
		m = nb % 10;
		ft_putnbr(nb / 10);
		ft_putchar(m);
	}
}

/*
int	main(void)
{
	int	nb;

	nb = -65;
	ft_putnbr(nb);
	return (0);
}
*/
