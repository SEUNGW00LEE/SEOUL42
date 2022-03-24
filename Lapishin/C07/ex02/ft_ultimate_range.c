/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:39:03 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/21 20:37:12 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	value;
	int	*arr;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == 0)
		return (-1);
	i = 0;
	value = min;
	while (i < max - min)
	{	
		arr[i] = value;
		i++;
		value++;
	}
	*range = arr;
	return (max - min);
}
