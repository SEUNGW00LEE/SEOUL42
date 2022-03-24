/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:27:55 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/13 21:52:27 by seungwol         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	j;

	dest_length = count_length(dest);
	src_length = count_length(src);
	i = 0;
	if (size <= dest_length)
		return (size + src_length);
	j = dest_length;
	while (j < size - 1 && src[i] != '\0')  
	{	
		dest[j] = src[i];
		j ++;
		i ++;
	}
	dest[j] = '\0';
	return (dest_length + src_length);
}
