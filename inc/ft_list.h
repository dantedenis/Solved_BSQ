/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:24:43 by bstrong           #+#    #+#             */
/*   Updated: 2021/09/06 14:24:44 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <fcntl.h>
# include "ft_string.h"

int		g_size_map;
char	g_empty;
char	g_block;
char	g_solver;

typedef struct s_list
{
	char	**map;
	int		len;
	int		i;
	int		j;
	int		max;
}t_list;

int		ft_open_file(char *str);
int		list_malloc(t_list **list, int row);
t_list	*fill_my_map(int row, int lenstr, char *str);
void	print_solution(t_list **map);
void	free_all(t_list **map, int **arr);

#endif
