/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:03:05 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/21 15:36:34 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_len(char *str)
{	
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

void	put_strs(int size, char **strs, char *str_join, char *sep)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{	
			*str_join = strs[i][j++];
			str_join ++;
		}
		j = 0;
		if (i != size - 1)
		{
			while (sep[j])
			{
				*str_join = sep[j++];
				str_join ++;
			}
		}
	}
	*str_join = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		str_len;
	int		sep_len;
	char	*str_join;

	if (size == 0)
	{
		str_join = (char *)malloc(1);
		*str_join = '\0';
		return (str_join);
	}
	i = -1;
	str_len = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			j ++;
		str_len += j ;
	}
	sep_len = count_len(sep);
	str_join = malloc(sizeof(char) * (str_len + sep_len * (size - 1) + 1));
	put_strs(size, strs, str_join, sep);
	return (str_join);
}
