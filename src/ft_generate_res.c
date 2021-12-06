/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_res.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:25:07 by bstrong           #+#    #+#             */
/*   Updated: 2021/09/06 14:25:08 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_generate_res.h"

int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

int	**creat_arr_int(int len)
{
	int	**new;
	int	i;
	int	j;

	new = (int **) malloc(sizeof(int *) * (g_size_map + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < g_size_map + 1)
	{
		new[i] = (int *) malloc(sizeof(int) * (len + 1));
		if (!new[i])
			return (NULL);
		j = -1;
		while (++j < len + 1)
			if (i == 0 || j == 0)
				new[i][j] = 0;
	}
	return (new);
}

void	fill_arr(int **arr, int i, int j)
{
	arr[i][j] = 1 + min3(arr[i - 1][j], arr[i - 1][j - 1], arr[i][j - 1]);
}

int	**dynamic_prog(t_list **map)
{
	int	**arr;
	int	i;
	int	j;

	arr = creat_arr_int((*map)->len);
	(*map)->max = 0;
	i = 0;
	while (++i < (g_size_map + 1) && arr)
	{
		j = 0;
		while (++j < (*map)->len + 1)
		{
			if ((*map)->map[i - 1][j - 1] == g_block)
				arr[i][j] = 0;
			else
				fill_arr(arr, i, j);
			if ((*map)->max < arr[i][j])
			{
				(*map)->max = arr[i][j];
				(*map)->i = i - 1;
				(*map)->j = j - 1;
			}
		}
	}
	return (arr);
}
