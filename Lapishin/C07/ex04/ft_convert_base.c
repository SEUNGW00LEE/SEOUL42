/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:38:38 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/21 10:31:34 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_putnbr_base(int nbr, char *base);

int	is_invalid(char *base, int *base_len)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (1);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i] == base[i + j])
				return (1);
			j++;
		}
		i++;
	}
	*base_len = i;
	return (0);
}

int	convert_num(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_minus(char *str, int *i)
{
	int	sign;
	int	tmp;

	sign = 1;
	tmp = *i;
	while (str[tmp] == '+' || str[tmp] == '-')
	{
		if (str[tmp] == '-')
			sign *= -1;
		tmp++;
	}
	*i = tmp;
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	i;
	int	is_minus;
	int	num;
	int	tmp_num;

	i = 0;
	if (is_invalid(base, &base_len))
		return (0);
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	is_minus = check_minus(str, &i);
	num = 0;
	tmp_num = convert_num(str[i], base);
	while (tmp_num != -1)
	{
		num *= base_len;
		num += tmp_num;
		i++;
		tmp_num = convert_num(str[i], base);
	}
	return (is_minus * num);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from_to_int;
	char	*arr;
	int		k;

	k = 0;
	if (is_invalid(base_from, &k) || is_invalid(base_from, &k))
		return (0);
	from_to_int = ft_atoi_base(nbr, base_from);
	arr = ft_putnbr_base(from_to_int, base_to);
	return (arr);
}
