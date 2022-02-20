/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:32:47 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/13 17:45:47 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_data[5][5];
extern int	g_flag;
extern int	g_col_up[4];
extern int	g_col_down[4];
extern int	g_row_left[4];
extern int	g_row_right[4];

int	up_to_down(void)
{
	int	i;
	int	cnt;
	int	max_h;
	int	j;

	i = 1;
	while (i <= 4)
	{
		cnt = 0;
		max_h = -1;
		j = 1;
		while (j <= 4)
		{
			if (g_data[j][i] > max_h)
				max_h = g_data[j][i];
			if (g_data[j][i] >= max_h)
				cnt++;
			j++;
		}
		if (cnt != g_col_up[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	down_to_up(void)
{
	int	i;
	int	cnt;
	int	max_h;
	int	j;

	i = 1;
	while (i <= 4)
	{
		cnt = 0;
		max_h = -1;
		j = 4;
		while (j >= 1)
		{
			if (g_data[j][i] > max_h)
				max_h = g_data[j][i];
			if (g_data[j][i] >= max_h)
				cnt++;
			j--;
		}
		if (cnt != g_col_down[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	left_to_right(void)
{
	int	cnt;
	int	max_h;
	int	i;
	int	j;

	i = 1;
	while (i <= 4)
	{
		cnt = 0;
		max_h = -1;
		j = 1;
		while (j <= 4)
		{
			if (g_data[i][j] > max_h)
				max_h = g_data[i][j];
			if (g_data[i][j] >= max_h)
				cnt++;
			j++;
		}
		if (cnt != g_row_left[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	right_to_left(void)
{
	int	cnt;
	int	max_h;
	int	i;
	int	j;

	i = 1;
	while (i <= 4)
	{
		cnt = 0;
		max_h = -1;
		j = 4;
		while (j >= 1)
		{
			if (g_data[i][j] > max_h)
				max_h = g_data[i][j];
			if (g_data[i][j] >= max_h)
				cnt++;
			j--;
		}
		if (cnt != g_row_right[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	check_col_row(void)
{
	int	check;

	check = 1;
	check *= up_to_down();
	check *= down_to_up();
	check *= left_to_right();
	check *= right_to_left();
	g_flag = check;
}
