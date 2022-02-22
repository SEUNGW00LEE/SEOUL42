/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:45:22 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/21 20:36:37 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*newstr;
	int		src_len;
	int		i;

	i = 0;
	src_len = ft_length(src);
	newstr = (char *)malloc(sizeof(char) * src_len + 1);
	while (src[i])
	{
		newstr[i] = src[i];
		i ++;
	}
	newstr[i] = '\0';
	return (newstr);
}
