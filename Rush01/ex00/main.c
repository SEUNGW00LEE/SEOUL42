/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:33:09 by seungwol          #+#    #+#             */
/*   Updated: 2022/02/13 17:45:48 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		g_data[5][5];
int		g_flag = 0;
int		g_col_up[4];
int		g_col_down[4];
int		g_row_left[4];
int		g_row_right[4];

void	get_solution(int row, int col);

int	check_argv(char *str, int *com, int i, int j)
{
	int	space;

	space = 1;
	while (str[++i] != '\0')
	{
		if (!(str[i] == ' ' || (str[i] >= '1' && str[i] <= '4')))
			return (0);
		if (!space && str[i] != ' ')
			return (0);
		if (str[i] == ' ')
		{
			if (space || j == 16)
				return (0);
			space = 1;
		}
		if (str[i] != ' ' && space)
		{
			com[j++] = str[i] - '0';
			space = 0;
		}
	}
	if (j != 16)
		return (0);
	return (1);
}

int	start_argv1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_argv_result(char *str, int *com)
{
	int	i;
	int	j;
	int	result;

	j = 0;
	i = start_argv1(str);
	result = check_argv(str, com, i, j);
	return (result);
}

void	div_argv(int *com)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 4)
			g_col_up[i] = com[i];
		else if (i < 8)
			g_col_down[i - 4] = com[i];
		else if (i < 12)
			g_row_left[i - 8] = com[i];
		else
			g_row_right[i - 12] = com[i];
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*str_temp;
	int	i;
	int	result;	

	if (argc != 2)
		write(1, "Error\n", 6);
	else
	{
		str_temp = (int *)malloc(sizeof(int) * 16);
		result = check_argv_result(*argv, str_temp);
		if (result)
		{
			i = 1;
			div_argv(str_temp);
			get_solution(1, 1);
			if (!g_flag)
				write(1, "Error\n", 6);
		}
		else
			write(1, "Error\n", 6);
		free(str_temp);
	}
	return (0);
}
