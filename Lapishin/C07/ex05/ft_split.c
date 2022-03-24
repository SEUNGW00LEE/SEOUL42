/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:17:46 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/21 20:36:58 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{	
		if (charset[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

int	ft_len(char *s, char *charset)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (ft_is_charset(s[i], charset) && s[i])
			i ++;
		if (s[i] != '\0')
			len ++;
		while (!ft_is_charset(s[i], charset) && s[i])
			i ++;
	}
	return (len);
}

char	*ft_rj(int w_len, char *str)
{	
	char	*tmp;
	int		k;

	tmp = malloc(sizeof(char) * (w_len + 1));
	if (!tmp)
		return (0);
	k = 0;
	while (w_len > 0)
	{
		tmp[k] = *(str - w_len);
		k ++;
		w_len --;
	}
	tmp[k] = '\0';
	return (tmp);
}

char	**ft_split(char *str, char *charset)
{
	char	**r;
	int		size;
	int		j;
	int		w_len;

	j = 0;
	size = ft_len(str, charset);
	r = malloc(sizeof(char *) * (size + 1));
	if (!r)
		return (0);
	while (*str && j < size)
	{
		w_len = 0;
		while (*str && ft_is_charset(*str, charset))
			str ++;
		while (*str && !ft_is_charset(*str, charset))
		{
			w_len ++;
			str ++;
		}
		r[j] = ft_rj(w_len, str);
		j ++;
	}
	r[j] = 0;
	return (r);
}
