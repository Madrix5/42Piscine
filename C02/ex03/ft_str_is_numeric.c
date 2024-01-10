/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:26:39 by adrijime          #+#    #+#             */
/*   Updated: 2023/12/05 18:07:47 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	cont;

	i = 0;
	cont = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			cont = 0;
		i++;
	}
	return (cont);
}

/*
int	main(void)
{
	char	string[] = "9h3l4";
	int		result;

	result = ft_str_is_alpha(string);
	printf("%d", result);
	return (0);
}
*/
