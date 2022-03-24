/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:24:50 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/08 19:21:29 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	func_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{	
		func_swap(&tab[i], &tab[size - i - 1]);
		i ++;
	}
}
