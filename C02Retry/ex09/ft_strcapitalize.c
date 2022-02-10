/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:21:36 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/09 11:28:17 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] -= 32;
		else if ((str[i] > 31 && str[i] < 48) || (str[i] > 122 && str[i] < 127)
			|| (str[i] > 90 && str[i] < 97) || (str[i] > '9' && str[i] < 'A'))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[i + 1] -= 32;
		}
		else
		{
			if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
				str[i + 1] += 32;
		}
		i ++;
	}
	return (str);
}
