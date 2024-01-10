/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:50:17 by adrijime          #+#    #+#             */
/*   Updated: 2023/12/07 14:04:32 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			ft_may(str[i]);
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i - 1] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
				str[i] 
		i++;
		}
	}
}
