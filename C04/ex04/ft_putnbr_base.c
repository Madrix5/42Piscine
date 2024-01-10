/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:12:08 by adrijime          #+#    #+#             */
/*   Updated: 2023/12/14 19:26:00 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_base_error(char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if (str[0] == '\0' || len == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= ' ' || str[i] == 127 || str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;
	int				len;

	len = ft_base_error(base);
	nb = (unsigned int)nbr;
	if (len <= 1 || base[0] == '\0')
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = (unsigned int)(-nbr);
	}
	if (nb <= (unsigned int)(len))
		ft_putchar(base[nb]);
	else
	{
		ft_putnbr_base(nb / len, base);
		ft_putnbr_base(nb % len, base);
	}
}
