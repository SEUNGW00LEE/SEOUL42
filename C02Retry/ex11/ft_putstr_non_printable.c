/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:38:42 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/09 19:28:05 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	mk_sixteen_div(unsigned char temp);
void	mk_sixteen_mod(unsigned char temp);

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	temp;

	i = 0;
	while (str[i])
	{	
		temp = (unsigned char) str[i];
		if (temp < 32 || temp > 126)
		{	
			write(1, "\\", 1);
			mk_sixteen_div(temp);
			mk_sixteen_mod(temp);
		}
		else
			write(1, &temp, 1);
		i ++;
	}
}

void	mk_sixteen_div(unsigned char temp)
{
	unsigned char	div;

	div = temp / 16;
	if (div > 9)
		div = (div % 10) + 'a';
	else
		div += '0';
	write(1, &div, 1);
}

void	mk_sixteen_mod(unsigned char temp)
{
	unsigned char	mod;

	mod = temp % 16;
	if (mod > 9)
		mod = (mod % 10) + 'a';
	else
		mod += '0' ;
	write(1, &mod, 1);
}
