/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:39:42 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/10 09:54:53 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	src_length;

	i = 0;
	src_length = 0;
	while (src[src_length] != '\0')
	{
		src_length ++;
	}
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i ++;
	}
	if (src_length <= n)
	{
		while (i < n)
		{
			dest[i] = '\0';
			i ++;
		}
	}
	return (dest);
}
