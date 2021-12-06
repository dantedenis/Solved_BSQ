/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_in_map.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:24:25 by bstrong           #+#    #+#             */
/*   Updated: 2021/09/06 14:24:26 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_IN_MAP_H
# define FT_CHECK_IN_MAP_H

# include <fcntl.h>
# include <unistd.h>
# include "ft_string.h"
# include "ft_list.h"
# include "ft_generate_res.h"

# define BUF 256000

void	init_glob(char s1, char s2, char s3);
int		check_first_line(int fd, char *buf);
int		get_strlen(char *ch);
int		check_line(char *ch);
int		ft_check_in_map(char *str, t_list **map);

#endif
