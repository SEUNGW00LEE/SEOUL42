/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:14:38 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/09 18:05:44 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		if (str[0] == '\0')
		{
			return (1);
		}
		if (str[i] < 32 || str[i] == 127)
		{
			return (0);
		}
		i ++;
	}
	return (1);
}
