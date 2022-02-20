/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:22:39 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/10 18:59:36 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{	
			j = 0;
			while (to_find[j] && str[i] == to_find[j])
			{
				i ++;
				j ++;
			}
			if (to_find[j] == '\0')
				return (&str[i - j]);
			i --;
		}
		i ++;
	}
	return (0);
}
