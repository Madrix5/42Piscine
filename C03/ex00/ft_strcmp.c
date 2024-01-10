/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:14:55 by adrijime          #+#    #+#             */
/*   Updated: 2023/12/11 19:35:15 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

/*
int	main(void)
{
	char	*s1;
	char	*s2;
	int		resultado;

	s1 = "Aola";
	s2 = "Holi";
	resultado = ft_strcmp(s1, s2);
	printf("%d\n", resultado);
	return (0);
}
*/
