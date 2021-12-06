/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:25:29 by bstrong           #+#    #+#             */
/*   Updated: 2021/09/06 14:25:31 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_open_file(char *str)
{
	return (open(str, O_RDONLY));
}

int	list_malloc(t_list **list, int row)
{
	*list = (t_list *)malloc(sizeof(t_list));
	if (!(*list))
		return (-1);
	(*list)->map = (char **)malloc(sizeof(char *) * row);
	if (!(*list)->map)
		return (-1);
	return (1);
}

t_list	*fill_my_map(int row, int lenstr, char *str)
{
	t_list	*new;
	int		i;
	int		count;
	int		j;

	if (list_malloc(&new, row) < 0)
		return (NULL);
	i = -1;
	new->len = lenstr;
	count = 0;
	while (++i < row)
	{
		new->map[i] = (char *) malloc(sizeof(char) * (lenstr + 1));
		if (!new->map[i])
			return (NULL);
		j = -1;
		while (str[count] && str[count] != '\n' && j < lenstr)
			(new->map)[i][++j] = str[count++];
		++count;
		(new->map)[i][j + 1] = '\0';
	}
	return (new);
}

void	print_solution(t_list **map)
{
	int	i;
	int	j;
	int	pi;
	int	pj;
	int	max;

	max = (*map)->max;
	pi = (*map)->i;
	pj = (*map)->j;
	i = -1;
	while (++i < g_size_map)
	{
		j = -1;
		while (++j < (*map)->len)
		{
			if ((i > (pi - max) && i <= pi) && (j > (pj - max) && j <= pj))
				write(1, &g_solver, 1);
			else
				write(1, &(*map)->map[i][j], 1);
		}
		write(1, "\n", 1);
	}
}

void	free_all(t_list **map, int **arr)
{
	int	i;

	i = -1;
	while (++i < g_size_map)
		free((*map)->map[i]);
	free((*map)->map);
	free(*map);
	i = -1;
	while (++i < g_size_map + 1)
		free(arr[i]);
	free(arr);
}
