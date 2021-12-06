/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:24:53 by bstrong           #+#    #+#             */
/*   Updated: 2021/09/06 14:24:55 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_in_map.h"

void	file_display(void)
{
	char	str[BUF];
	int		count;
	int		fd;

	fd = open("input.map", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	while (fd > 0)
	{	
		count = read(0, str, BUF);
		write(fd, str, count);
		if (!count)
			break ;
	}
	close (fd);
}

int	start_pr(char *name_map, t_list **map)
{
	int	**result;

	if (ft_check_in_map(name_map, map) < 0)
	{
		write(2, "map error\n\n", 11);
		return (-1);
	}
	result = dynamic_prog(map);
	if (!result)
		return (-2);
	print_solution(map);
	free_all(map, result);
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*map;
	int		i;
	int		temp;

	map = NULL;
	if (argc < 2)
	{
		file_display();
		temp = start_pr("input.map", &map);
		if (temp == -2)
		{
			write(2, "error memory\n", 13);
			return (-2);
		}
	}
	i = 0;
	while (++i < argc)
	{
		temp = start_pr(argv[i], &map);
		if (temp == -2)
			write(2, "error memory\n", 13);
	}
	return (0);
}
