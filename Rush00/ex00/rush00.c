/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:59:31 by adrijime          #+#    #+#             */
/*   Updated: 2023/11/25 18:45:03 by jfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	cur_x;
	int	cur_y;

	cur_y = 1;
	while (cur_y <= y && x > 0 && y > 0)
	{
		cur_x = 1;
		while (cur_x <= x)
		{
			if ((cur_x == 1 && cur_y == 1) || (cur_x == x && cur_y == y))
				ft_putchar ('o');
			else if ((cur_x == 1 && cur_y == y) || (cur_x == x && cur_y == 1))
				ft_putchar ('o');
			else if (cur_x == 1 || cur_x == x)
				ft_putchar ('|');
			else if (cur_y == 1 || cur_y == y)
				ft_putchar ('-');
			else
				ft_putchar (' ');
			cur_x++;
		}
		ft_putchar ('\n');
		cur_y++;
	}
}
