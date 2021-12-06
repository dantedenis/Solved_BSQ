/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_in_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:25:00 by bstrong           #+#    #+#             */
/*   Updated: 2021/09/06 14:25:01 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_in_map.h"

void	init_glob(char s1, char s2, char s3)
{
	g_empty = s1;
	g_block = s2;
	g_solver = s3;
}

int	check_first_line(int fd, char *ch)
{
	int	i;
	int	count;

	i = 0;
	while (1)
	{
		count = read(fd, &ch[i], 1);
		if (ch[i++] == '\n')
			break ;
	}
	ch[i] = '\0';
	i = 0;
	if (!ch || !(*ch > '0' && *ch <= '9'))
		return (-1);
	g_size_map = ft_atoi(ch);
	while (ch[i] >= '0' && ch[i] <= '9')
		++i;
	if (ch[i] == '\0' || ch[i] == '\n')
		return (-1);
	init_glob(ch[i], ch[i + 1], ch[i + 2]);
	i += 3;
	if (ch[i] != '\n' || (g_block == g_empty || g_block == g_solver
			|| g_block == g_solver) || g_size_map < 1 || ch[i + 1] != '\0')
		return (-1);
	return (0);
}

int	get_strlen(char *ch)
{
	int	i;

	i = 0;
	while (ch[i] != '\n' && ch[i] != '\0')
		++i;
	return (i);
}

int	check_line(char *ch)
{
	int	i;
	int	count;
	int	len;
	int	temp;

	i = -1;
	len = 0;
	count = 0;
	temp = get_strlen(ch);
	while (ch[++i])
	{
		if (ch[i] == '\n')
		{
			if (len != temp)
				return (-1);
			len = -1;
			++count;
		}
		else if (ch[i] != g_block && ch[i] != g_empty)
			return (-1);
		++len;
	}
	if (count != g_size_map)
		return (-1);
	return (temp);
}

int	ft_check_in_map(char *str, t_list **map)
{
	int		fd;
	int		count;
	char	ch[BUF];

	fd = ft_open_file(str);
	if (fd < 1 || check_first_line(fd, ch) < 0)
		return (-1);
	while (1)
	{
		count = 0;
		count = read(fd, &ch, BUF);
		if (!count)
			break ;
		ch[count + 1] = '\0';
		count = check_line(ch);
		if (count < 0)
			return (-1);
		*map = fill_my_map(g_size_map, count, ch);
	}
	close(fd);
	return (0);
}
