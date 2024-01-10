/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:59:31 by adrijime          #+#    #+#             */
/*   Updated: 2023/11/29 13:40:25 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

char	get_char(int row, int col, int max_rows, int max_cols)
{
	if (row == 1)
	{
		if (col == 1)
			return ('/');
		else if (col == max_cols)
			return ('\\');
		else
			return ('*');
	}
	else if (row == max_rows)
	{
		if (col == 1)
			return ('\\');
		else if (col == max_cols)
			return ('/');
		else
			return ('*');
	}
	else if (col == 1 || col == max_cols)
	{
		return ('*');
	}
	return (' ');
}

void	rush(int x, int y)
{
	int	cur_x;
	int	cur_y;

	if (x <= 0 || y <= 0)
		write(1, "Parámetros inválidos.\n", 24);
	else
	{
		cur_y = 1;
		while (cur_y <= y)
		{
			cur_x = 1;
			while (cur_x <= x)
			{
				ft_putchar(get_char(cur_y, cur_x, y, x));
				cur_x++;
			}
			ft_putchar ('\n');
			cur_y++;
		}
	}
}
