/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:54:42 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/10 13:41:37 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				length;

	length = 0;
	i = 0;
	while (src[length])
	{
		length ++;
	}
	if (size == 0)
		return (length);
	while (src[i] && i < size - 1)
	{	
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (length);
}
