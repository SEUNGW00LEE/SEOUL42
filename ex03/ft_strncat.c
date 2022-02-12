/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:04:34 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/10 17:16:07 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_length(char *str)
{	
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length ++;
	}
	return (length);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				dest_length;
	int				src_length;

	dest_length = count_length(dest);
	src_length = count_length(src);
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[dest_length] = src[i];
		dest_length ++;
		i ++;
	}
	dest[dest_length] = '\0';
	return (dest);
}
