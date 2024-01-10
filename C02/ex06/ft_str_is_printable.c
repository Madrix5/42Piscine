/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:17:30 by adrijime          #+#    #+#             */
/*   Updated: 2023/12/05 18:24:01 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	cont;

	i = 0;
	cont = 1;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
			cont = 0;
		i++;
	}
	return (cont);
}
