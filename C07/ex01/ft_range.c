/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:53:16 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/21 15:36:05 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	value;

	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	value = min;
	while (i < max - min)
	{	
		arr[i] = value;
		i++;
		value++;
	}
	return (arr);
}
