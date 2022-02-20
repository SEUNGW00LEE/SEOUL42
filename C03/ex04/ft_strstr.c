/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:22:39 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/13 17:55:47 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{	
			k = i;
			j = 0;
			while (to_find[j] && str[k] == to_find[j])
			{
				k ++;
				j ++;
			}
			if (to_find[j] == '\0')
				return (&str[k - j]);
		}
		i ++;
	}
	return (0);
}
