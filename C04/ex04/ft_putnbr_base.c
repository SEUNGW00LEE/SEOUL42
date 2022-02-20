/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:18:30 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/14 12:26:20 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_length(char *str)
{
	long long	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int	check_base(char *base, long long *base_len)
{	
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[i + j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	*base_len = i;
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{	
	long long	temp;
	long long	base_len;
	long long	is_base_vaild;
	long long	i;

	temp = (long long) nbr;
	is_base_vaild = check_base(base, &base_len);
	if (is_base_vaild == 1)
		return ;
	if (temp < 0)
	{
		temp *= -1;
		write(1, "-", 1);
	}
	if (temp != 0)
	{
		i = temp % base_len;
		temp = temp / base_len;
		ft_putnbr_base(temp, base);
		write(1, &base[i], 1);
	}
}
