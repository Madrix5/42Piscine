/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:58:12 by adrijime          #+#    #+#             */
/*   Updated: 2023/12/14 20:55:47 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	int				j;
	unsigned int	n;

	i = 0;
	j = 0;
	n = 0;
	if (nb == 0)
		return (dest);
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && n < nb)
	{
		dest[i + j] = src[j];
		j++;
		n++;
	}
	dest[i + j] = '\0';
	return (dest);
}
