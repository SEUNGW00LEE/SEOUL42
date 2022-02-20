/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:37:54 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/14 10:13:39 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_minus(char *str, int *i)
{
	int	count_minus;
	int	tmp;

	tmp = 0;
	count_minus = 0;
	while ((str[tmp] >= 9 && str[tmp] <= 13) || str[tmp] == 32)
		tmp ++;
	while (str[tmp] == '-' || str[tmp] == '+')
	{
		if (str[tmp] == '-')
		{
			count_minus ++;
			tmp ++;
		}
		else if (str[tmp] == '+')
			tmp ++;
	}
	*i = tmp;
	return (count_minus);
}

int	ft_atoi(char *str)
{	
	int	i;
	int	count_minus;
	int	nb;

	i = 0;
	nb = 0;
	count_minus = check_minus(str, &i);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{	
			nb *= 10;
			nb += str[i] - '0';
			i ++;
		}
		else
			return (0);
	}
	if (count_minus % 2 == 1)
		nb *= -1;
	return (nb);
}
