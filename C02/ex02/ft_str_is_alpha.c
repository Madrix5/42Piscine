/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:44:35 by adrijime          #+#    #+#             */
/*   Updated: 2023/12/01 14:23:31 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	cont;
	int	cont2;

	i = 0;
	cont = 0;
	cont2 = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			cont = 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			cont = 1;
		else
			cont2 = 0;
		i++;
	}
	if (cont2 == 0)
		return (0);
	return (1);
}

/*
int	main(void)
{
	char	string[] = "Hol";
	int		result;

	result = ft_str_is_alpha(string);
	printf("%d", result);
	return (0);
}
*/
