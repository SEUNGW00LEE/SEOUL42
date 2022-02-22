/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:11:17 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/21 20:32:33 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_invalid(char *base, int *base_len);

int	count_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int	recur_putnbr(long long temp, int base_len, int j)
{
	int	i;

	while (temp != 0)
	{
		i = temp % base_len;
		temp = temp / base_len;
		j ++;
	}
	return (j);
}

char	*ft_putarr(int nbr, char *base, char *arr, int j)
{
	int			i;
	int			base_len;
	long long	temp;

	temp = (long long) nbr;
	base_len = count_length(base);
	if (temp == 0)
	{
		arr[0] = base[0];
		arr[1] = '\0';
		return (arr);
	}
	if (temp < 0)
	{
		temp *= -1;
		j ++;
	}
	arr[j--] = '\0';
	while (temp != 0)
	{
		i = temp % base_len;
		temp = temp / base_len;
		arr[j--] = base[i];
	}
	return (arr);
}

char	*ft_putnbr_base(int nbr, char *base)
{	
	long long	temp;
	int			base_len;
	char		*arr;
	int			j;

	temp = (long long) nbr;
	if (is_invalid(base, &base_len))
		return (0);
	j = 0;
	if (temp < 0)
		temp *= -1;
	j = j + recur_putnbr(temp, base_len, j);
	if (nbr < 0)
	{
		arr = malloc((sizeof(char) * j + 1) + 1);
		arr[0] = '-';
	}	
	else
		arr = malloc((sizeof(char) * j) + 1);
	if (!arr)
		return (NULL);
	arr = ft_putarr(nbr, base, arr, j);
	return (arr);
}
