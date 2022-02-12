/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:57:45 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/10 17:19:51 by seungwol         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	dest_length;
	int	src_length;
	int	i;

	dest_length = count_length(dest);
	src_length = count_length(src);
	i = 0;
	while (i < src_length && src[i] != '\0')
	{
		dest[dest_length] = src[i];
		dest_length ++;
		i ++;
	}
	dest[dest_length] = '\0';
	return (dest);
}
