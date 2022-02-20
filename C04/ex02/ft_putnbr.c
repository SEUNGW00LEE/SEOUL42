/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:34:47 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/14 09:32:38 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{	
	long long	nbb;
	int			div;
	char		numb;

	nbb = (long long) nb;
	if (nbb < 0)
	{
		nbb *= -1;
		write(1, "-", 1);
	}	
	if (nbb > 9)
	{
		div = nbb % 10;
		nbb /= 10;
		ft_putnbr(nbb);
		numb = '0' + div;
		ft_write(numb);
	}
	else
	{
		div = nbb % 10;
		numb = '0' + div;
		ft_write(numb);
	}
}
