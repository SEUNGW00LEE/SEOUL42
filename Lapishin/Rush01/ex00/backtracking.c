/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:31:51 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/13 17:45:46 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int		g_data[5][5];
extern int		g_flag;
int				g_row_check[7][7];
int				g_col_check[7][7];

void	check_col_row(void);

void	print_result(void)
{
	int		i;
	int		j;
	char	temp;

	if (g_flag == 1)
	{
		i = 1;
		j = 1;
		while (i < 5)
		{
			j = 1;
			while (j < 5)
			{
				temp = g_data[i][j] + '0';
				write(1, &temp, 1);
				if (j != 4)
					write(1, " ", 1);
				j++;
			}
			i++;
			write(1, "\n", 1);
		}
	}
}

void	check_one(int row, int col, int k, int val)
{
	g_row_check[row][k] = val;
	g_col_check[col][k] = val;
}

void	get_solution(int row, int col)
{
	int	k;

	if (col > 4)
		return ;
	if (row > 4)
	{
		check_col_row();
		print_result();
		return ;
	}
	k = 0;
	while (++k <= 4)
	{
		if (g_row_check[row][k] == 0 && g_col_check[col][k] == 0)
		{
			check_one(row, col, k, 1);
			g_data[row][col] = k;
			get_solution(row, col + 1);
			if (g_flag)
				return ;
			if (col == 4)
				get_solution(row + 1, 1);
			check_one(row, col, k, 0);
		}
	}
}
